#include "soleq.h"
#include <cassert>
#include <unordered_set>
#include <cmath>


using namespace std;/*
void printExtendedMatrix(vector< vector<double> > a);
void printAnswer(Soleq::Answer answer);*/

namespace {

	vector<double> operator-(vector<double>a, vector<double>b) {
		if (a.size() != b.size()) {
			throw std::runtime_error("the sizes of the vectors to be subtracted do not match");
		}
		vector<double> res(a.size());
		for (int i = 0; i < a.size(); i++) {
			res[i] = a[i] - b[i];
		}
		return res;
	}
	vector<double> operator*(vector<double>a, double b) {
		vector<double> res(a.size());
		for (int i = 0; i < a.size(); i++) {
			res[i] = a[i] * b;
		}
		return res;
	}
	vector<double> operator*(double a, vector<double> b) {
		return b * a;
	}
	vector<double> operator/(vector<double>a, double b) {
		if (fabs(b) < eps) {
			throw std::runtime_error("division by zero");
		}
		std::vector<double> res(a.size());
		for(int i = 0; i < a.size(); ++i) {
			res[i] = a[i] / b;
		}
		return res;
	}
	
	bool isFreeUnknownInExtendedMatrix(vector<vector<double>> a, int column) { // check column (return true if column contains only zeros)
		bool isAllZerosInColumn = true;
		for (int line = 0; line < a.size() && isAllZerosInColumn; line++) {
			if (fabs(a[line][column]) > eps) {
				isAllZerosInColumn = false;
			}
		}
		return isAllZerosInColumn;
	}
	
	void eraseRowFromExtendedMatrix(vector<vector<double>> & a, int column) {
		/*
		For instance deleting second column from this matrix:
		{ {a, b, c, d},
		  {e, f, g, h},
		  {i, j, k, l}
		}
		=>
		{ {a, c, d},
		  {e, g, h},
		  {i, k, l}
		}
		*/
		for (int i = 0; i < a.size(); i++) {
			for (int j = column; j + 1< a[i].size(); j++) {
				a[i][j] = a[i][j + 1];
			}
			a[i].resize(a[i].size() - 1);
		}
	}
}


Soleq::Soleq(std::vector<std::vector<double> > a) { // should be (n) x (n + 1) matrix, where n > 0
	int size_of_line = a.size() + 1;
	if (a.empty()) {
		throw BadArgumentInConstructor();
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i].size() != size_of_line) {
			throw BadArgumentInConstructor();
		}
	}
	ext_matrix = a;
}

Soleq::Answer Soleq::solve() {
	auto acopy = this->ext_matrix;
	
	auto & a = this->ext_matrix;
	
	std::unordered_set<int> freeUnknownRowIndeces;
	for (int i = 0; i < a.size() - 1; i++) {
		if (isFreeUnknownInExtendedMatrix(a, i)) {
			freeUnknownRowIndeces.insert(i);
			eraseRowFromExtendedMatrix(a, i);
		}
	}
//	printf("Delete AllZerosRow\n");
//	printExtendedMatrix(a);
	
    for (int i=0; i<a.size(); i++) {
        // Search for maximum in this column
        double maxEl = abs(a[i][i]);
        int maxRow = i;
        for (int k=i+1; k<a.size(); k++) {
            if (abs(a[k][i]) > maxEl) {
                maxEl = abs(a[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k=i; k<a[i].size();k++) {
            double tmp = a[maxRow][k];
            a[maxRow][k] = a[i][k];
            a[i][k] = tmp;
        }

        // Make all rows below this one 0 in current column
        for (int k=i+1; k<a.size(); k++) {
			double c = -a[k][i]/a[i][i];
            for (int j=i; j<a[k].size(); j++) {
                if (i==j) {
                    a[k][j] = 0;
                } else {
                	if (std::isnan(c)) {
                		//printf("IsNan\n");
						continue;
					}
                    a[k][j] += c * a[i][j];
                }
            }
        }
    }

//	printf("Edited Matrix1:\n");
//	printExtendedMatrix(a);

	bool thereAreAllZerosInOneOfTheLines = false; // except for the last column
	for (int i = 0; i < a.size();) {
		bool isAllZerosInLine = true; // except for the last column
		for (int j = 0; j < a[i].size() - 1 && isAllZerosInLine; j++) {
			if (fabs(a[i][j]) > eps) {
				isAllZerosInLine = false;
			}
		}
		if (isAllZerosInLine) { // general solution answer
			thereAreAllZerosInOneOfTheLines = true;
			if (fabs(a[i][a[i].size() - 1]) > eps || std::isnan(a[i][a[i].size() - 1])) { // in the last column is not zero => can't solve
				throw CanNotSolve();
			}
			else {
				a.erase(a.begin() + i);
				continue; // without i++
			}
		}
		i++;
	}
//	printf("Edited Matrix2:\n");
//	printExtendedMatrix(a);
	
	/*std::unordered_set<int> freeUnknownRowIndeces;
	for (int i = 0; i < a.size(); i++) {
		if (isFreeUnknownInExtendedMatrix(a, i)) {
			freeUnknownRowIndeces.insert(i);
			eraseRowFromExtendedMatrix(a, i);
		}
	}
	printf("Delete AllZerosRow\n");
	printExtendedMatrix(a);*/
	
	if (thereAreAllZerosInOneOfTheLines) {
		if (a.size() != 0) {
			if (a[0].size() != 0) {
				
				int unknows = a[0].size() - 1; 
				int rang = a.size();
				std::vector<double> line(unknows + 1, 0); // + 1 column of free numbers
				// line has info about root = a*x1 + b*x2 + c*x3 + ... + d as {a, b, c, ..., d}
				std::vector<std::vector<double>> answer(unknows, line);
				if (unknows > rang) {
					
					
					for (int i = rang; i < unknows; i++) {
						//a[i] = a[i] / a[i][i];
						answer[i][i] = 1;
					}
					//print(answer);
					for (int i = rang - 1; i >= 0; i--) {
						int firstNotZeroJ = -1;
						for (int j = i; j < unknows; j++) {
							if (a[i][j] != 0) {
								if (firstNotZeroJ == -1) {
									firstNotZeroJ = j;
									continue;
								}
								answer[i][j] = -a[i][j] / a[i][firstNotZeroJ];
							}
						}
						if (firstNotZeroJ != -1) {
							answer[i][unknows] = a[i][unknows] / a[i][firstNotZeroJ];
						}
						else {
							assert(false);
						}
					}
					for (int i = rang - 1; i >= 0; i--) { // last substract...
						for (int j = rang - 1; j >= 0; j--) {
							if (fabs(answer[i][j]) > eps) {
								answer[i] = answer[i] - answer[j]*(a[i][j]/a[i][i]); // so?
								answer[i][j] = 0;
							}
						}
					}
					return answer;
				}
				else {
					//throw std::runtime_error("unexpected error 1");
				}
			}
			else {
				throw std::runtime_error("unexpected error 2");
			}
		}
		else {
			Answer answer(std::vector<double>(acopy.size()));
			for (int i = 0; i < answer.general_solution.size(); i++) {
				answer.general_solution[i][i] = 1;
			}
			return answer;
		}
		
	}
    // Solve equation Ax=b for an upper triangular matrix A (values answer)
    vector<double> x(a.size());
    for (int i=a.size()-1; i>=0; i--) {
        x[i] = a[i][a.size()]/a[i][i];
        for (int k=i-1;k>=0; k--) {
            a[k][a.size()] -= a[k][i] * x[i];
        }
    }
    
    if (!freeUnknownRowIndeces.empty()) {
    	vector<vector<double>> fullAnswer(a.size() + freeUnknownRowIndeces.size());
    	for (int i = 0, j = 0; i < fullAnswer.size(); i++) {
    		auto freeUnknownLineIndex = freeUnknownRowIndeces.find(i);
    		if (freeUnknownLineIndex != freeUnknownRowIndeces.end()) {
    			std::vector<double> temp(a.size() + freeUnknownRowIndeces.size() + 1, 0);
    			temp.at(i) = 1;
    			fullAnswer.at(i) = temp;
			}
    		else {
    			std::vector<double> temp(fullAnswer.size() + 1, 0);
    			temp[temp.size() - 1] = x[j++];
    			fullAnswer.at(i) = temp;
			}
		}
		return Answer(fullAnswer);
	}
    else {
    	return Answer(x);
	}
}




#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>

//double const eps  = 0.000001;

class Soleq { // System Of Linear EQuation
public:
	
	Soleq(std::vector<std::vector<double>>);
	
	struct CanNotSolve: public std::exception {
		const char * what() const noexcept override {
			return "Can't solve this system of linear equation";
		}
	};
	
	struct BadArgumentInConstructor: public std::exception {
		const char * what() const noexcept override {
			return "bad argument: the provided argument should be matrix (n) x (n + 1)";
		}
	};
	
	struct Answer {
		Answer(std::vector<double> answer) {
			std::vector<double> line(answer.size() + 1);
			std::vector<std::vector<double>> general_solution(answer.size(), line);
			for (int i = 0; i < general_solution.size(); i++) {
				general_solution[i][line.size() - 1] = answer[i];
			}
			this->general_solution = general_solution;
		}
		Answer(std::vector<std::vector<double>> answer) : general_solution(answer) {}
		
		bool thereAreNoFreeUnknown() { // only decision
			bool res = true;
			for (int i = 0; i < general_solution.size(); i++){
				for(int j = 0; j + 1 < general_solution[i].size(); j++){
					if(general_solution[i][j] != 0) res = false;
					//std::cout << a[i][j] << "\t";
				}
				//std::cout << "\n";
			}
			return res;
		}
		
		std::vector<std::vector<double>> general_solution; // general solution matrix (n)x(n + 1)
	};
	
	Answer solve();
	
private:
	Soleq();
	Soleq(const Soleq&);
	Soleq& operator=(const Soleq&);
	
	std::vector<std::vector<double> > ext_matrix;
};

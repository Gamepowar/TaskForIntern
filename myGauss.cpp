#include <iostream>
#include<iomanip>
#include <vector>
using namespace std;

namespace my{
	vector<vector<double > > gauss(vector<vector < double > > x);
}

double sum (vector<double > arr){
	double sum = 0;
	for (int i = 0; i < arr.size(); i++){
		sum += arr[i];
	}
	return sum;
}

struct Variable{
	double x4;
	double x5;
};

vector<vector<double > > my::gauss(vector<vector<double > > x){
	double koef = 0;
	for(int k = 1; k < x.size(); k++){
		for (int i = k; i < x.size() ; i++){
			if(x[k - 1][k - 1] == 0) continue;
			koef = x[i][k - 1] / x[k - 1][k - 1];
			cout << ">>>>>>>>>>		x [" << i  << "][" << k - 1 << "] = "  << x[i][k - 1] << endl;
			cout << ">>>>>>>>>>		x [" << k - 1  << "][" << k - 1 << "] = "  << x[k - 1][k - 1] << endl;
			cout << ">>>>>>>>>>		koef :" << koef << "\n";
			for(int j = 0; j < x[i].size(); j++){
				cout << ">>>>>>>>>>		x [" << k - 1 << "][" << j << "] = "  << x[k-1][j] << endl;
				x[i][j] -= x[k - 1][j] * koef;
				cout << "x [" << i << "][" << j << "] = " << x[i][j] << endl;
			}
		}
	}
	for(int i = 0; i < x.size(); i++){
		for(int j = 0; j < x[i].size(); j++){
			cout << x[i][j] << "\t";
		}
		cout << endl;
	}
	vector<vector<double > > fundResh(x[0].size() - 1);
	vector<double > temp (x[0].size()  - x.size() - 1);
	cout << "tenp_size = " << temp.size() << "\n";
	cout << "fundResh_size = " << fundResh.size() << endl;
	for(int i = fundResh.size() - 1; i >= 0; i--){
		cout << "test1\n";
//		cout << ">>>>>>>>   i = " << i << endl;
		for(int j = temp.size() - 1, l = 0; j >= 0; j--, l++){
			cout <<">>>>>>        if :" << fundResh.size() - l - 1  << "  i : " << i << "\n";
			if(i == fundResh.size() - l - 1  && i >= fundResh.size() - temp.size()){
				temp[j] = 1;
				cout << "1t\n";
				continue;
			}
			else if(i >= fundResh.size() - temp.size()){
				temp[j] = 0;
				cout << "2t\n";
				continue;
			}
			else{
				temp[j] = 0;
		//		cout << "3t\n";
				for(int k = fundResh.size() - 1; k > i ; k--){
		//			cout << "slomalos`?\n";
					cout << "i = " << i << ", k = " << k << endl;
					cout << "i = " << i << ", j = " << j << endl;
				//	temp.at(i) = x.at(i).at(k) *  fundResh.at(k).at(j);
					temp[j] -= (x[i][k] * fundResh[k][j]) / x [i][i];
					cout << "x [" << i  << "][" << k << "] =  " << x[i][k] << ",   fundResh  = " << fundResh[k][j] << endl;
					cout << "temp[" << j << "] = " << temp[j] << endl;
				} 
				cout << "3t\n";
				continue;
			}
		}
		fundResh[i] = temp;
	//	temp.clear();
	}
	for (int i = 0; i < fundResh.size(); i++){
		for(int j = 0; j < fundResh[i].size(); j++){
			cout << fundResh[i][j] << " ";
		}
		cout << endl;
	}
	return fundResh;
/*	for (int i = res.size(); i > 0; i++){
		for(int j = res.size(); j > 0; j++)
			res[i].push_back(sum(x[i]) &&  ? == 0) 
	}
/*	
	for(int i = x.size(); i > 0; i--){
		]
	}
/*	for(int i = x.size() - 1; i > 0; i--){
		res[i] = a[i][n] / a[i][i];
		for (int j = x.size(); j > i; c--){
			res[i] -= a[i][j] * x[j] / a[i][i]; 
		}
	}*/
	
//		cout << k << "\n\n";
	
//	cout << "Check func\n";
/*	for(int i = 0; i < x.size(); i++){
		for (int j = 0; j < x[i].size(); j++){
			cout << x[i][j] << " ";
		}
		cout << endl;
	} */
//	return x;
} 



int main(){
	cout.setf(ios::fixed);  // ????? ? ????????????? ??????? 
    cout.precision(6);
	int N = 5;
	vector<vector<double > > x;
	vector<double> temp;
	vector<double> a(N, 0);
	temp.push_back(16);
	temp.push_back(4);
	temp.push_back(4);
	temp.push_back(2);
	temp.push_back(1);
	temp.push_back(0);
	x.push_back(temp);
	temp.clear();
	temp.push_back(121);
	temp.push_back(1);
	temp.push_back(11);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(0);
	x.push_back(temp);
	temp.clear();
	temp.push_back(121);
	temp.push_back(16);
	temp.push_back(11);
	temp.push_back(4);
	temp.push_back(1);
	temp.push_back(0);
	x.push_back(temp);
	temp.clear();
/*	vector<double> temp1(6, 0);
	x.push_back(temp1);
	x.push_back(temp1);*/
	vector<double > r;
	vector<vector<double > > t;
	r.push_back(1);
	r.push_back(2);
	r.push_back(0);
//	r.push_back(0);
	t.push_back(r);
	r.clear();
	r.push_back(3);
	r.push_back(5);
	r.push_back(6);
//	r.push_back(0);
	t.push_back(r);
	vector<vector<double > > f = my:: gauss(t);
	for(int i = 0; i < f.size(); i++){
		for (int j = 0; j < f[i].size(); j++){
			cout << f[i][j] << " ";
		}
		cout << endl;
	}
	  
	for(int i = 0; i < x.size(); i++){
		cout << i << " :";
		for (int j = 0; j < x[i].size(); j++){
			cout << x[i][j] << " ";
		}
		cout << endl;
	} 
/*	vector<vector<double > > newV = my::gauss(x);
	cout << "Check\n";
/*	for(int i = 0; i < x[0].size(); i++){
		for (int j = 0; j < x.size(); j++){
			cout << newV[j][i] << " ";
		}
		cout << endl;
	} /*
/*	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			
		}
	}*/
	
}

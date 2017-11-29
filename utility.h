#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

template<typename T> 
	int load(const string &filename,vector<vector<T>> &vec	)
{
	ifstream ifs(filename);
	string str;	
	while (getline(ifs,str))
	{
		T data;
		stringstream ss(str);
		vector<T> v;
		while (ss>>data)
			v.push_back(data);
		vec.push_back(v);			
	}
	ifs.close();
	return 0;
}
template<typename T> 
	int save(const string &filename,vector<vector<T>> &vec	)
{
	ofstream ofs(filename);
	for (int i=0;i<vec.size();i++)
	{
		for (int j=0;j<vec[i].size();j++)
			ofs<<vec[i][j]<<" ";
		ofs<<endl;
	}
	ofs.close();	
	return 0;
}
template<typename T> 
	int display(vector<vector<T>> &vec	)
{	
	for (int i=0;i<vec.size();i++)
	{
		for (int j=0;j<vec[i].size();j++)
			cout<<vec[i][j]<<" ";
		cout<<endl;
	}	
	return 0;
}

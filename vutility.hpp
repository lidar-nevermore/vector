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
	int save(const vector<vector<T>> &vec,const string &filename)
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
	int display(const vector<vector<T>> &vec)
{	
	for (int i=0;i<vec.size();i++)
	{
		for (int j=0;j<vec[i].size();j++)
			cout<<vec[i][j]<<" ";
		cout<<endl;
	}	
	return 0;
}

int split(const string &line,vector<int>& line_ints)
{
	line_ints.clear();
	string dlm=" ,\n";	
	size_t current =line.find_first_not_of(dlm,0);
	size_t next =line.find_first_of(dlm,current);
	while (current!=string::npos)
	{		
		line_ints.push_back(atoi(line.data()+current));
		//line_ints.push_back(atoi(line.substr(current,next-current).c_str()));
		current =line.find_first_not_of(dlm,next);
		next =line.find_first_of(dlm,current);
	}		
	if( line_ints.empty())return 0;	
	return 1;
}

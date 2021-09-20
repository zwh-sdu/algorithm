#include<bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	string root;
	int n;
	cin>>n;
	getchar();
	getline(cin,root);
	for(int cishu=0;cishu<n;cishu++)
	{
		string tem;
		getline(cin,tem);
		if(tem[0]!='/')	tem=root+"/"+tem;
		for(int i=0;i<tem.size();i++)
		{
			if(tem[i]=='/')
			{
				tem[i]=' ';
			}
		}
		//root=tem;
		stringstream ttem;
		ttem<<tem;		
		//cout<<"标记"<<ttem.str()<<endl;
		string t;
		vector<string> v;
		while(ttem>>t)
		{
		//	cout<<"t为"<<t<<endl;
			if(t==".") continue;//遇到.跟没有一样
			else if(t=="..")
			{
				if(!v.empty())
				{
					v.pop_back();
				}
			}
			else v.push_back(t);
		}	
		if(v.empty())	cout<<"/";
		for(int i=0;i<v.size();i++)
		{
			cout<<"/"<<v[i];
		}
		cout<<endl;
	}
	return 0;
}

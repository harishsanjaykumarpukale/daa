#include<bits/stdc++.h>

using namespace std;
int main(){
	string text,pttr;
	cout << "\nEnter the text:";
	cin >> text;
	//cout << text << endl;
	cout << "\nEnter the pattern:";
	cin >> pttr;

	pair<char,int> temp;
	map<char,int> table;

	map<char,int>::iterator it;

	int m = pttr.length(), n = text.length(),k,j,flag = 0;

	for (int i=0 ; i<m-1 ; i++){
		it=table.find(pttr[i]);

		if( it != table.end())
			(*it).second = m-1-i;
		else{
			temp.first = pttr[i];
			temp.second = m-1- i;
			table.insert(temp);
		}
	}

	for(it = table.begin() ; it !=table.end() ; it++)
		cout<< (*it).first << "  " << (*it).second <<endl;

	for(int i=m-1;i<n;){
		j=i;
		if(text[i] == pttr[m-1]){
			for( k=m-2,j=i-1; k>=0 ; k--,j--)
				if(text[j] != pttr[k])
					break;
			if(k==-1){
				cout << "The pattern is found at " << j+2 << " position" <<endl; 
				flag = 1;
			}

		}
		
		it = table.find(text[j]);

		if( it != table.end())
			i+=(*it).second;
		else
			i+=m;
	}

	if(flag == 0)
		cout << "The pattern is not found " <<endl;

	return 0;
}


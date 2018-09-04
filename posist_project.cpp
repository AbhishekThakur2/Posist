#include<iostream>
#include<set>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
#include<ctime>
#include<sstream>
using namespace std;
/*

The thought of the project was to first use blockchain. I couldnt visualise it properly so i dropped the idea of doing it through blockchain

I thought of creating a simple generic tree which stores the value of the structure defined in the question.
My hashing function was to add another character to every character in the string to make it encrypted. But i couldnt implement it due to shortage of time for me.
Also, the steps of the constraint of having the parent node having more value than sum of children node


*/


class Node{
	
	public:
		time_t time_present;
		string data;  // Owner of the id, ownder name, data of floating point
		static int NodeNumber;
		Node *parentNode;
		vector<Node *> children;
		Node *genesis;
			
		Node(string name, float value, Node* ptr){
			
			genesis = ptr;
			time_present = time(0);
			NodeNumber++;
			//hashing
			data = hash_func(name, value, NodeNumber);
		}
		
		
		//hash function concatenating 3 string for encryption in the order name, value, id
		string hash_func(string name, float value, int x)
		{
			string temp;
			//string s;
			//convert float to string
			ostringstream sss;
			sss<<value;
			string s(sss.str());
			//itoa(x, s, 10);
			temp.append(name);
			temp.append("$");
			temp.append(s);
			temp.append("$");
			
			ostringstream ssss;
			ssss<<x;
			string ss(ssss.str());
			temp.append(ss);
			temp.append("$");		
			return temp;	
		}
		
};


//function to add node in the generic tree
void add_node(Node *genesis_ptr, string name, float value)
{
	Node *temp = new Node(name, value, genesis_ptr);
	genesis_ptr->children.push_back(temp);
	
}



//function to search a node and validate it
void search(Node *genesis_ptr, string name)
{
	int flag=0;
	for(int i=0; i < genesis_ptr->children.size(); i++)
	{
		if((genesis_ptr->children[i])->data == name) 
		{
			cout<<"\n"<<genesis_ptr->children[i]->data;
			flag=1;
		}
	}
	if(flag==0)
	{
		cout<<"\n\nNOT FOUND";
		getchar();
		exit(0);
	}
	
	
}



int Node::NodeNumber =0;
//Node(name of the owner, data of floating point)




int main()
{
	
	
	string name;float value;
	
	
	cout<<"ENTER OWNER NAME: ";
	cin>>name;
	cout<<"ENTER OWNER DATA: ";
	cin>>value;
	cout<<"\nCongratulations! You are an owner. Please enter your name when you want to access your data";
	
	Node *genesis_ptr = new Node("NA", 0, genesis_ptr);	
	
	int ch;
	cout<<"\t\tMENU";
	cout<<"\n 1. Add owner";
	cout<<"\n 2. Access Data";
	cout<<"\n 0. Exit";
	
	while(ch!='0')
	{
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"\nEnter name of the owner: ";
				cin>>name;
				cout<<"\n Enter the value: ";
				cin>>value;
				add_node(genesis_ptr, name, value);
				cout<<"\nAdded!";
				break;
			case 2:
				cout<<"\nEnter your name to access: ";
				cin>>name;
				search(genesis_ptr, name);
				break;
			case 0:
				exit(0);
				
		}
		
	}
	
	
	return 0;
}

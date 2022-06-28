#include <iostream>
#include <vector>
#include <unordered_map>
#include "head.h"
using namespace std;
int main()
{

	cout<<"--------------------------------------------------------------------"<<endl;
	cout<<bold_on<<"                GOOD MORNING USER ! "<<bold_off<<endl<<endl;


	int ch=1;
	int ide=0;
	int count;
    unordered_map <int,chart *> m;
	while(ch!=6)
	{
		cout<<"1.Create Your Organizational chart "<<endl;
		cout<<"2.Visualize Your Organization in realtime  "<<endl;
		cout<<"3.Check Level of any Role "<<endl;
		cout<<"4.Raise Conflict "<<endl;
		cout<<"5.Inter Deptartment Request "<<endl;
		cout<<"6.Exit "<<endl;

		cout<<"Enter Your choice = "<<endl;
		cin>>ch;

		if(ch==1)
		{
			cout<<"Enter all different roles from top to bottom = "<<endl;
			chart * root ;
			root=buildorganchart();
			ide++;
			m[ide]=root;
			cout<<endl<<endl;
			cout<<"Built successfull with "<<bold_on<<" id = "<<ide<<bold_off<< endl;
		}
		else if(ch==2)
		{
			cout<<"Enter the id of your organization = ";
			cin>>count;
			cout<<endl;
			cout<<bold_on<<"       Your Organization Chart "<<bold_off<<endl;
			Beautifyy(m[count]);
			cout<<endl;
		}
		else if(ch==3)
		{
			cout<<"Enter the id of your organization = "<<endl;
			cin>>count;
			cout<<"Enter the Role name = ";
	        string s;
	 		cin>>s;
			cout<<endl;
			chart * abc=sear(s,m[count]);
			cout<<endl;
			if(abc!=NULL)
			cout<<bold_on<<char((heightboard(m[count])-heightboard(abc))+65)<<" Level "<<bold_off<<endl;
			else cout<<"No such Post exists ! "<<endl;
			cout<<endl;
		}
		else if(ch==4)
		{
			cout<<"Enter the id of your organization = "<<endl;
			cin>>count;
			cout<<"Enter your post = ";
			string s1,s2;
			cin>>s1;
			cout<<"Enter other party's post = ";
			cin>>s2;
			chart * a=sear(s1,m[count]);
			chart * b=sear(s2,m[count]);
			cout<<endl;
			if(a and b)
			{
				cout<<bold_on<<"To Raise Conflict "<<s1<<" and "<<s2<<" must talk to ";
				if(lca(m[count],a,b)->name == s1 )
				{
					cout<<s1;
				}
				else
				if(lca(m[count],a,b)->name == s2 )
				{
					cout<<s2;
				}
				else
				cout<<lca(m[count],a,b)->name<<endl<<bold_off;
			cout<<endl;
			}
			else cout<<"No such posts exists ! "<<endl;
		}
		else if(ch==5)
		{
			cout<<"Enter the id of your organization = "<<endl;
			cin>>count;
			cout<<"Enter your post = "<<endl;
			string s1,s2;
			cin>>s1;
			cout<<"Enter other party's post = "<<endl;
			cin>>s2;
			cout<<endl;
			cout<<bold_on;

			printPathBetweenNodes(m[count],s1,s2);
			cout<<bold_off;
			cout<<endl<<endl;
		}
		else if(ch==6)
		{
			cout<<bold_on;
			cout<<"THANK YOU USER "<<endl;
			cout<<"HAVE A GOOD DAY :) "<<endl;
			cout<<bold_off;
			return 0;
		}
		cout<<endl;		
	}
	return 0;
}
//BoardMember SeniorAssociate SoftwareEngineer JuniorEngineer1 -1 -1 JuniorEngineer2 -1 -1 TestingEngineer Intern1 -1 -1 Intern2 -1 -1 MarketingManager MarketingOfficier MarketingExecutive1 -1 -1 MarketingExecutive2 -1 -1 SalesOfficer SalesExecutive1 -1 -1 SalesExecutive2 -1 -1


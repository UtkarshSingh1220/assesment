#include<bits/stdc++.h>
using namespace std;
//creating array of string which have product name which excluded from basic tax
const vector<string> vex={"pills","medicine","tablet","book","chocolates","vegitables","chocolate","bar","bread","biscuit","snacks","milk","butter","meat","sugar","salt","spices"};
// creating string which signifies the string add the 5% imported value
const string im="imported";

int match(vector<string> x,string y){
	int res=1;
	for (int i = 0; i < x.size(); ++i)
	{
		
		if(y.find(x[i])<y.size()){
			res=0;
		}
	}
	return res;
}
vector<string> vec(vector<string> v)
{
	int n=v.size();
	vector<float> ar10;
	vector<float> ar5;
	vector<float> oval;
	vector<float> nval;
	vector<string> sval;
	vector<string> vstr;
	string tot="Total: ";
	string sal="Sales Taxes: ";
	float tax=0;

	for (int i = 0; i < v.size(); ++i)
	{


		string word;
		stringstream ss(v[i]);
		while(ss>>word){
			vstr.push_back(word);//put words into array of string from string sentence
		}
		sval.push_back(vstr[vstr.size()-1]); //put value as string
		oval.push_back(stof(vstr[vstr.size()-1]));
		nval.push_back(stof(vstr[vstr.size()-1])); //put vaule as float
		if(v[i].find(im)<v[i].size()+1){ //put value in 5% array
			float f=(nval[i]/100)*5;
			ar5.push_back(f);

		}else{
			ar5.push_back(0);
		}

		if(match(vex,v[i])){
			float f=(nval[i]/100)*10;
			ar10.push_back(f);

		}else{
			ar10.push_back(0);
		}
		float sum=ar10[i]+ar5[i]+nval[i]; //// include tax value
		
		sum=(int)(sum * 100 + .5);
		if((int)sum % 10<5 && (int)sum % 10>0 ){
			
			sum=((int)sum/10)*10+5;

		}
		
		sum=(float)sum / 100;//round value @ 2 decimal point
		nval[i]=sum;

		vstr.clear();
	}
	for (int i = 0; i < nval.size(); ++i)
	{
		tax=tax+(nval[i]-oval[i]); //calculate total sales tax
	}


	tax=(int)(tax * 100 + .5);
	tax=(float)tax / 100;
	int ai= tax*100;
	string aa,bb,cc;
	aa=to_string(ai);
	bb=aa.substr(0,aa.size()-2);
	if(bb==""){
		bb="0";
	}
	cc=aa.substr(aa.size()-2,aa.size());
	aa=bb+"."+cc;
	sal=sal+aa;         // creating Sales tax string with 2 decimal float value

	float total =accumulate(nval.begin(), nval.end(), float(0));
	total=(int)(total * 100 + .5);
	total=(float)total / 100;
	ai=total*100;
	aa=to_string(ai);
	bb=aa.substr(0,aa.size()-2);
	if(bb==""){
		bb="0";
	}
	cc=aa.substr(aa.size()-2,aa.size());
	aa=bb+"."+cc;
	tot=tot+aa;       // creating total string with 2 decimal float value

	for (int j = 0; j < v.size(); ++j)
	{
		string ss = " at";
		int n=v[j].find(ss);
		v[j].replace(n,3,":");
		int m=v[j].find(sval[j]);
		nval[j]=(int)(nval[j] * 100 + .5);
		ai=nval[j];
		aa=to_string(ai);
		bb=aa.substr(0,aa.size()-2);
		if(bb==""){
			bb="0";
		}
		cc=aa.substr(aa.size()-2,aa.size());
		aa=bb+"."+cc;
		v[j].replace(m,v[j].size()-m,aa); //add new value (product value + taxes) to vector string 
		
	}
	v.push_back(sal);// add sales tax string with value
	v.push_back(tot);// add total string with vaule
	return v;

}

int main()
{
	string s;
	vector<string> v;
	while(getline(cin,s))
	{
		if(s.empty())
			break;
		v.push_back(s);
	}
	v=vec(v);
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<endl;
	}
  return 0;
}
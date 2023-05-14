#include<vector>
#include<string>
#include<istream>
#include<ostream>
#include<cstring>
class bignum{
	friend std::ostream& operator<< (std::ostream& out,bignum x);
	private:
		std::vector<int>a;
		void format(){
			a.clear();
		}
	public:
		bignum(){this->format();a.push_back(0);};
		bignum(std::string x){
			this->format();
			for(int i=x.size()-1;i>=0;i--)	a.push_back(x[i]-'0');
		}
		bignum(char x[]){
			this->format();
			for(int i=strlen(x)-1;i>=0;i--)	a.push_back(x[i]-'0');
		}
		bignum(long long x){
			this->format();
			do{
				a.push_back(x%10);
				x/=10;
			}while(x);
		}
		int compare(bignum x){
			if(a.size()>x.a.size())	return 1;
			if(a.size()<x.a.size())	return -1;
			for(int i=a.size()-1;i>=0;i--){
				if(a[i]>x.a[i])	return 1;
				if(a[i]<x.a[i])	return -1;
			}
			return 0;
		}
		bool operator> (bignum x){
			return this->compare(x)==1;
		}
		bool operator== (bignum x){
			return this->compare(x)==0;
		}
		bool operator< (bignum x){
			return this->compare(x)==-1;
		}
		bool operator>= (bignum x){
			return this->compare(x)!=-1;
		}
		bool operator!= (bignum x){
			return this->compare(x)!=0;
		}
		bool operator<= (bignum x){
			return this->compare(x)!=1;
		}
		bignum operator+ (bignum x){
			bignum ans;ans.format();
			int t=0;
			for(int i=0;i<a.size()||i<x.a.size();i++){
				if(i<a.size())	t+=a[i];
				if(i<x.a.size())	t+=x.a[i];
				ans.a.push_back(t%10);
				t/=10;
			}
			if(t)	ans.a.push_back(t);
			return ans;
		}
		bignum operator+= (bignum x){
			*this=*this+x;
			return *this;
		}
		
};
std::istream& operator>> (std::istream& in,bignum& x){
	std::string tmp;
	in>>tmp;
	x=tmp;
	return in;
}
std::ostream& operator<< (std::ostream& out,bignum x){
	for(int i=x.a.size()-1;i>=0;i--)	out<<x.a[i];
	return out;
}

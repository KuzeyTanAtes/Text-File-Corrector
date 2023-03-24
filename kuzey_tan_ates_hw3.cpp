#include<iostream>
#include<fstream>
using namespace std;
class Date{
	public:
		int day,year;
		string month;
		Date(){	}
		Date(int day,string month,int year){
			this->day=day;
			this->month=month;
			this->year=year;
		}
};
class Player{
	private:
		string first,last;
		Date birthdate;
	public:
	    Player(string first,string last,int day,string month,int year){
	    	this->first=first;
	    	this->last=last;
	    	birthdate.day=day;
	    	birthdate.month=month;
	    	birthdate.year=year;
		}			
		int getDay(){
			return birthdate.day;
		}
		int getYear(){
			return birthdate.year;
		}
		void setMonth(string m){
			birthdate.month=m;
		}
		void printInfo(ostream &a){
			a<<first<<" "<<last<<" "<<birthdate.day<<" "<<birthdate.month<<" "<<birthdate.year<<endl;
		}
		
};
int main(){
	ifstream file1;
	ofstream file2;
	file1.open("input.txt");
	file2.open("output.txt");
	string first,last,month;
	int day,year;
	while(!file1.eof()){
		file1>>first>>last>>day>>month>>year;
		try{
			if(month.substr(0,3) == "Aug" && month.substr(0,4)!="Augu"){
			throw month;
			}
			else if(month.substr(0,3)=="Sep"&&month.substr(0,4) != "Sept"){
			throw month;
			}
			else if(month.substr(0,3)=="Feb"&&month.substr(0,4) != "Febr"){
			throw month;
			}
			else if(month.substr(0,3)=="Dec"&&month.substr(0,4) != "Dece"){
			throw month;
			}
			else if(month.substr(0,3)=="Oct"&&month.substr(0,4) != "Octo"){
			throw month;
			}
			else if(month.substr(0,3)=="Apr"&&month.substr(0,4) != "Apri"){
			throw month;
			}
			else{
				file2<<first<<" "<<last<<" "<<day<<" "<<month<<" "<<year<<endl;
			}
			}
			catch(...){
				Player obj(first,last,day,month,year);
				if(month.substr(0,3)=="Aug"){
					obj.setMonth("August");
					cout<<"Incorrectly inputted month: "<<month<<" is corrected to "<<"August"<<endl;
					obj.printInfo(file2);
					
				}
				else if(month.substr(0,3)=="Sep"){
					obj.setMonth("September");
					cout<<"Incorrectly inputted month: "<<month<<" is corrected to "<<"September"<<endl;
					obj.printInfo(file2);
				}
				else if(month.substr(0,3)=="Feb"){
					obj.setMonth("February");
					cout<<"Incorrectly inputted month: "<<month<<" is corrected to "<<"February"<<endl;
					obj.printInfo(file2);
				}
				else if(month.substr(0,3)=="Dec"){
					obj.setMonth("December");
					cout<<"Incorrectly inputted month: "<<month<<" is corrected to "<<"December"<<endl;
					obj.printInfo(file2);
				}
				else if(month.substr(0,3)=="Oct"){
					obj.setMonth("October");
					cout<<"Incorrectly inputted month: "<<month<<" is corrected to "<<"October"<<endl;
					obj.printInfo(file2);
				}else if(month.substr(0,3)=="Apr"){
					obj.setMonth("April");
					cout<<"Incorrectly inputted month: "<<month<<" is corrected to "<<"April"<<endl;
					obj.printInfo(file2);
				}
			}
			
		
	}
	
file1.close();
file2.close();
return 0;	
}


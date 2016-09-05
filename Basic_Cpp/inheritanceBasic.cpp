#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
		Student(string firstName, string lastName, int id, vector<int> scores) : Person(firstName,lastName,id){
	  			this->testScores = scores;
		}  
  		char calculate()
  		{
  			float avg=0;
  			for (int i = 0; i < testScores.size(); ++i)
  				avg=avg+testScores[i];
  			avg = avg / testScores.size();
  			if (avg>=90)
 	 			return 'O';
 	 		else if(avg >= 80) {
                return 'E'; // Exceeds Expectations
            }
            else if(avg >= 70) {
                return 'A'; // Acceptable
            }
            else if(avg >= 55) {
                return 'P'; // Poor
            }
            else if(avg >= 40) {
                return 'D'; // Dreadful
            }
            else {
                return 'T'; // Troll
            }
  		}
};


int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}
#include "Student.h"

//Overloads < operator, used to sort students by name
//Basically changed the < operator to do what we want 
//Should NOT be used to actually compare students
bool Student::operator<(const Student& s) {
	bool a;
	//first we check if the last names are the same
	if (nameLast.length() == (s.getLastName()).length()) { //if they are the same legth
		for (int i = 0; i < (nameLast.length()) - 1; i++) {
			if (nameLast[i] == (s.getLastName())[i]) // check if they are the same last name, if the are
				a = (nameFirst[0] > (s.getFirstName())[0] && nameFirst[1] > (s.getFirstName())[1]); //check first name
			else // if they aren't
				a = (nameLast[0] > (s.getLastName())[0] && nameLast[1] > (s.getLastName())[1]);
		}
	}
	else //if they aren't the same length
		a = (nameLast[0] > (s.getLastName())[0] && nameLast[1] > (s.getLastName())[1]);
	return a;
}
//Overloads > operator, used to sort by grade
bool Student::operator>(const Student& s) {
	return rawScore > s.getRawScore();
}
//Overloads << operator, used too print Student
ostream& operator << (ostream & os, const Student& s) {
	os << " " << setw(20) << left << s.nameFirst << setw(12) << left << s.nameLast
		<< "   \t" << s.rawScore << "    \t" << setprecision(4) << setw(18)
		<< s.letterGrade << endl;
	return os;
}
//Overloads >> operator, to be used with student ptrs
istream& operator>>(istream& is, Student* s) {
	is >> s->nameLast >> s->nameFirst >> s->rawScore;
	return is; 
}
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
using namespace std;
using std::string;

enum GRADE { F, D, CMINUS, C, CPLUS, BMINUS, B, BPLUS, AMINUS, A };
const int BAR = 60;

class Student
{
private:
	string nameFirst;
	string nameLast;
	double rawScore;
	double percentRank;
	GRADE pointGrade;
	GRADE curveGrade;
	string letterGrade;
public:
	void setFirstName(string s) {
		nameFirst = s;
	}
	void setLastName(string s) {
		nameLast = s;
	}
	void setRawScore(double s) {
		rawScore = s;
	}
	void setPercent(double p) {
		percentRank = p;
	}
	void setPointGrade(GRADE g) {
		pointGrade = g;
	}
	void setCurveGrade(GRADE g) {
		curveGrade = g;
	}

	void setLetterGrade() {
		GRADE g;
		if ((rawScore >= BAR) && (curveGrade >= pointGrade))
			g = curveGrade;
		else
			g = pointGrade;
		switch (g)
		{
		case F:
			letterGrade = "F";
			break;
		case D:
			letterGrade = "D";
			break;
		case CMINUS:
			letterGrade = "C-";
			break;
		case C:
			letterGrade = "C";
			break;
		case CPLUS:
			letterGrade = "C+";
			break;
		case BMINUS:
			letterGrade = "B-";
			break;
		case B:
			letterGrade = "B";
			break;
		case BPLUS:
			letterGrade = "B+";
			break;
		case AMINUS:
			letterGrade = "A-";
			break;
		case A:
			letterGrade = "A";
			break;
		}
	}
	string getFirstName()const{
		return nameFirst;
	}
	string getLastName()const{
		return nameLast;
	}
	double getRawScore()const{
		return rawScore;
	}
	double getPointGrade()const {
		return pointGrade;
	}
	double getPercent()const{
		return percentRank;
	}
	string getLetterGrade()const{
		return letterGrade;
	}
	bool operator>(const Student&);
	bool operator>=(const Student&);
	bool operator==(const Student&);
	bool operator<(const Student&);
	bool operator<=(const Student&);
	friend ostream& operator << (ostream &, const Student&);
	friend istream& operator >>(istream &, Student*);
};

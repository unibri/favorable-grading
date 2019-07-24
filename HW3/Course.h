#pragma once
#include "Student.h"

class Course {
private:
	struct Node {
		Student* p;
		Node* next;
	};
	Node* nameHead;
	Node* gradeHead;
	double classSize;
public:
	Course(){
		nameHead = nullptr;
		gradeHead = nullptr;
		classSize = 0;
	}
	~Course();
	void insertGradeNode(Student* );
	void insertNameNode(Student*);
	void reverse();
	void grabData();
	void setRank();
	void assignPointGrade();
	void assignCurveGrade();
	void assignLetterGrade();
	void displayGradeReport()const;
};


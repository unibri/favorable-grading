#include "Course.h"

int main() {
	Course *c;
	c = new Course;
	c->grabData(); 
	c->reverse();
	c->setRank();
	c->assignPointGrade();
	c->assignCurveGrade();
	c->assignLetterGrade();
	c->displayGradeReport();
	system("pause");
}
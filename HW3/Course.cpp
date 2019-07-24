#include "Course.h"
//Destructor
Course::~Course() {
	Node *nodePtr;
	Node *nextPtr;
	nodePtr = gradeHead;
	//if there is no list
	if (!gradeHead) {
		return;
	}
	while (nodePtr != nullptr) {
		nextPtr = nodePtr->next; 
		delete nodePtr; 
		nodePtr = nextPtr;
	}

}
//REVERSES name linked list 
void Course::reverse(){
	Node* current = nameHead;
	Node* prev = nullptr, *next = nullptr;
	while (current != nullptr){
		next = current->next; //Store next 
		current->next = prev; //Reverse current node ptr
		//Move to the next node
		prev = current;
		current = next;
	}
	nameHead = prev;
}
//CREATES linked list based on sorted grades (descending)
void Course::insertGradeNode(Student *s) {
	Node *newNode; //used to point to new node
	Node *nodePtr; //used to traverse 
	Node *prevNode = nullptr; //used to store previous node
	//allocates newNode to store Student
	newNode = new Node; 
	newNode->p = s; 
	
	if (!gradeHead) { //if there are no nodes
		gradeHead = newNode; //sets gradeHead 
		newNode->next = nullptr; //there is no next node; 
	}
	else {
		nodePtr = gradeHead; //start at the head
		prevNode = nullptr; 
		while (nodePtr != nullptr && *(nodePtr->p) > *s) { //while student p > student s
			prevNode = nodePtr; //prevNode is the node nodePtr is pointing to
			nodePtr = nodePtr->next;  //nodePtr moves on to the next node
		}
		if (prevNode == nullptr) { //meaning student s has the highest grade
			gradeHead = newNode;  //the newNode becomes the greadHead
			newNode->next = nodePtr; 
		}
		else {
			prevNode->next = newNode; //insert newNode next to prevNode
			newNode->next = nodePtr;
		}
	}
}
//CREATES linked list based on sorted last names 
void Course::insertNameNode(Student *t) {
	Node *nodePtr;
	Node *newNode; 
	Node *prevNode = nullptr; 
	newNode = new Node; 
	newNode->p = t;
		if (!nameHead) {
			nameHead = newNode; 
			newNode->next = nullptr;
		}
		else {
			nodePtr = nameHead; 
			prevNode = nullptr; 
			while (nodePtr != nullptr && *(nodePtr->p) < *t) {
				prevNode = nodePtr;
				nodePtr = nodePtr->next;
			}
			if (prevNode == nullptr) {
				nameHead = newNode;
				newNode->next = nodePtr;
			}
			else {
				prevNode->next = newNode; //insert newNode next to prevNode
				newNode->next = nodePtr;
			}
		}
}
//GRABS data and sets student data members, sends student pointer to both linked lists
void Course::grabData() {
	ifstream data;
	string fileName;
	//Asks user to type file name and opens file
	cout << "Enter file name: ";
	cin >> fileName;
	data.open(fileName.c_str());
	//Checking for error
	if (data.fail()) {
		cerr << "Error opening file";
		exit(3);
	}
	Student *s; //studentPtr
	string line; 
	classSize = 0; //Initizalizes classSize to set as a counter
	if (data) {
		while (data) {
			s = new Student; //new student 
			data >> s;  
			insertGradeNode(s);  //adds student to list sorted by grade
			insertNameNode(s);  //adds student to list sorted by grade
			classSize++; //increases classSize by one each time new a student is added
			getline(data, line); //moves on to the next line	
		}
	}
}
//Sets rank of students using grade linked list
void Course::setRank() {
	Node *currentPtr = gradeHead; //used to keep track of current node
	Node *nextPtr = gradeHead->next; //used to keep track of next node
	double j = classSize - 1; //to calculate rank
	//go through list
	while(currentPtr){
		if (nextPtr == nullptr) { //first checks if next is blank -- meaning we are at the end of the list
			currentPtr->p->setPercent(j / classSize);
			currentPtr = nullptr; //breaks out
		}
		else if (currentPtr->p->getRawScore() == nextPtr->p->getRawScore()) { //if concurrent raw scores are =
			currentPtr->p->setPercent(j / classSize); //sets current student percent
			nextPtr->p->setPercent(j / classSize); //sets next student percent
			currentPtr = nextPtr; // we move on two students
			nextPtr = nextPtr->next;
			currentPtr = nextPtr;
			nextPtr = nextPtr->next;
			j -= 2; 
		}
		else { //we set the current student percent
			currentPtr->p->setPercent(j / classSize);
			currentPtr = nextPtr; // we move on to the next node
			nextPtr = nextPtr->next;
			j--;
		}
	}
}
//Assigns point grade to students
void Course::assignPointGrade() {
	Node *nodePtr = gradeHead; //used to go through nodes
	Node *nextPtr = gradeHead->next; //keeps track of next node
	
	while (nodePtr) {
		if (nextPtr==nullptr) { 
			if (nodePtr->p->getRawScore() > 93)
				nodePtr->p->setPointGrade(A);
			else if (nodePtr->p->getRawScore() > 90)
				nodePtr->p->setPointGrade(AMINUS);
			else if (nodePtr->p->getRawScore() > 87)
				nodePtr->p->setPointGrade(BPLUS);
			else if (nodePtr->p->getRawScore() > 83)
				nodePtr->p->setPointGrade(B);
			else if (nodePtr->p->getRawScore() > 80)
				nodePtr->p->setPointGrade(BMINUS);
			else if (nodePtr->p->getRawScore() > 77)
				nodePtr->p->setPointGrade(CPLUS);
			else if (nodePtr->p->getRawScore() > 73)
				nodePtr->p->setPointGrade(C);
			else if (nodePtr->p->getRawScore() > 67)
				nodePtr->p->setPointGrade(CMINUS);
			else if (nodePtr->p->getRawScore() > 60)
				nodePtr->p->setPointGrade(D);
			else
				nodePtr->p->setPointGrade(F);
			nodePtr = nullptr;
			break;
		}
		if (nodePtr->p->getRawScore() > 93)
			nodePtr->p->setPointGrade(A);
		else if (nodePtr->p->getRawScore() > 90)
			nodePtr->p->setPointGrade(AMINUS);
		else if (nodePtr->p->getRawScore() > 87)
			nodePtr->p->setPointGrade(BPLUS);
		else if (nodePtr->p->getRawScore() > 83)
			nodePtr->p->setPointGrade(B);
		else if (nodePtr->p->getRawScore() > 80)
			nodePtr->p->setPointGrade(BMINUS);
		else if (nodePtr->p->getRawScore() > 77)
			nodePtr->p->setPointGrade(CPLUS);
		else if (nodePtr->p->getRawScore() > 73)
			nodePtr->p->setPointGrade(C);
		else if (nodePtr->p->getRawScore() > 67)
			nodePtr->p->setPointGrade(CMINUS);
		else if (nodePtr->p->getRawScore() > 60)
			nodePtr->p->setPointGrade(D);
		else
			nodePtr->p->setPointGrade(F);
		nodePtr = nextPtr; // we move on to the next node
		nextPtr = nextPtr->next;
	}
}
//Assigns curved grade to students
void Course::assignCurveGrade() {
	Node *nodePtr = gradeHead;
	Node *nextPtr = gradeHead->next;

	while (nodePtr) {
		if (nextPtr == nullptr) {
			if (nodePtr->p->getPercent() >= .9)
				nodePtr->p->setCurveGrade(A);
			else if (nodePtr->p->getPercent() >= .75 && nodePtr->p->getPercent() < .9)
				nodePtr->p->setCurveGrade(AMINUS);
			else if (nodePtr->p->getPercent() >= .6 && nodePtr->p->getPercent() < .75)
				nodePtr->p->setCurveGrade(BPLUS);
			else if (nodePtr->p->getPercent() >= .45 && nodePtr->p->getPercent() < .6)
				nodePtr->p->setCurveGrade(B);
			else if (nodePtr->p->getPercent() >= .35 && nodePtr->p->getPercent() < .45)
				nodePtr->p->setCurveGrade(BMINUS);
			else if (nodePtr->p->getPercent() >= .25 && nodePtr->p->getPercent() < .35)
				nodePtr->p->setCurveGrade(CPLUS);
			else if (nodePtr->p->getPercent() >= .15 && nodePtr->p->getPercent() < .25)
				nodePtr->p->setCurveGrade(C);
			else if (nodePtr->p->getPercent() >= .10 && nodePtr->p->getPercent() < .15)
				nodePtr->p->setCurveGrade(CMINUS);
			else if (nodePtr->p->getPercent() >= .5 && nodePtr->p->getPercent() < .10)
				nodePtr->p->setCurveGrade(D);
			else
				nodePtr->p->setCurveGrade(F);
			nodePtr = nullptr;
			break;
		}
		if (nodePtr->p->getPercent() >= .9)
			nodePtr->p->setCurveGrade(A);
		else if (nodePtr->p->getPercent() >= .75 && nodePtr->p->getPercent() < .9)
			nodePtr->p->setCurveGrade(AMINUS);
		else if (nodePtr->p->getPercent() >= .6 && nodePtr->p->getPercent() < .75)
			nodePtr->p->setCurveGrade(BPLUS);
		else if (nodePtr->p->getPercent() >= .45 && nodePtr->p->getPercent() < .6)
			nodePtr->p->setCurveGrade(B);
		else if (nodePtr->p->getPercent() >= .35 && nodePtr->p->getPercent() < .45)
			nodePtr->p->setCurveGrade(BMINUS);
		else if (nodePtr->p->getPercent() >= .25 && nodePtr->p->getPercent() < .35)
			nodePtr->p->setCurveGrade(CPLUS);
		else if (nodePtr->p->getPercent() >= .15 && nodePtr->p->getPercent() < .25)
			nodePtr->p->setCurveGrade(C);
		else if (nodePtr->p->getPercent() >= .10 && nodePtr->p->getPercent() < .15)
			nodePtr->p->setCurveGrade(CMINUS);
		else if (nodePtr->p->getPercent() >= .5 && nodePtr->p->getPercent() < .10)
			nodePtr->p->setCurveGrade(D);
		else
			nodePtr->p->setCurveGrade(F);
		nodePtr = nextPtr;
		nextPtr = nextPtr->next;
	}
}
void Course::assignLetterGrade() {
	Node *nodePtr = gradeHead;
	Node *nextPtr = gradeHead->next;

	while (nodePtr) {
		if (nextPtr == nullptr) {
			nodePtr->p->setLetterGrade();
			nodePtr = nullptr;
			break;
		}
		else {
			nodePtr->p->setLetterGrade();
			nodePtr = nextPtr;
			nextPtr = nextPtr->next;
		}
	}
}
//CREATES new text file
void Course::displayGradeReport()const {
	Node *nodePtr = nameHead; //used to go through nodes
	ofstream data; 
	data.open("report.txt");
	data << setw(45) << "******LISTING BY NAME******" << endl;
	data << "First Name\t  " << " Last name    \t" << "Raw Score \t" << "Final Grade \t" << endl << endl;
	while (nodePtr) {
		data << *(nodePtr->p);
		nodePtr = nodePtr->next;
	}
	data << endl << endl << endl << endl << endl;
	nodePtr = gradeHead;
	data << setw(45) << "******LISTING BY GRADE******" << endl;
	while (nodePtr) {
		data << *(nodePtr->p);
		nodePtr = nodePtr->next;
	}
	cout << "Report is saved in a file: report.txt" << endl;
	data.close(); 
}
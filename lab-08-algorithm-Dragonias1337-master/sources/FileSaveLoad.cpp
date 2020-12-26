
#include "stdafx.h"
#include "Header.h"
#include <algorithm>
#include <iostream>
#include <conio.h>
using namespace std;


bool greaterString(Student s1, Student s2)
{
	return s1.Name.compare(s2.Name) < 0;
}

bool greaterAverageRating(Student s1, Student s2)
{
	double average1 = 0;
	int i;
	for (i = 0; i < s1.Ratings.size(); i++)
	{
		average1 += s1.Ratings[i];
	}
	average1 /= i;

	double average2 = 0;
	for (i = 0; i < s2.Ratings.size(); i++)
	{
		average2 += s2.Ratings[i];
	}
	average2 /= i;

	return average1 > average2;
}

bool hasRatingsBadMark(unsigned rating)
{
	return rating <= 2;
}

bool hasStudentBadMark(Student s1)
{	
	auto p = find_if(s1.Ratings.begin(), s1.Ratings.end(), hasRatingsBadMark);	
	return p!=s1.Ratings.end();
}

bool hasRatingsExcellentMarks(unsigned rating)
{
	return rating >= 5;
}

bool hasStudentExcellentMarks(Student s1)
{	
	return count_if(s1.Ratings.begin(), s1.Ratings.end(), hasRatingsExcellentMarks) == s1.Ratings.size();
}

bool hasStudentExcellentMathMark(Student s1)
{
	for (int i = 0; i < s1.Ratings.size() && i < s1.Subjects.size(); i++)
	{
		if (s1.Ratings[i] >= 5 && s1.Subjects[i].compare("Math") == 0)
			return true;
	}
	return false;
}



void SortByName(vector<Student> &vec)
{
	sort(vec.begin(), vec.end(), greaterString);
}

void SortByRating(vector<Student> &vec)
{
	sort(vec.begin(), vec.end(), greaterAverageRating);
}

size_t CountTwoness(const vector<Student> &vec)
{	
	return count_if(vec.begin(), vec.end(), hasStudentBadMark);
}

size_t CountExcellent(const vector<Student> &vec)
{
	return count_if(vec.begin(), vec.end(), hasStudentExcellentMarks);
}

vector<Student> VectorMathExcellent(const vector<Student> &vec)
{
	vector<Student> excellentMathStudents(count_if(vec.begin(), vec.end(), hasStudentExcellentMathMark));
	copy_if(vec.begin(), vec.end(), excellentMathStudents.begin(), hasStudentExcellentMathMark);
	return excellentMathStudents;
}

vector<string> GroupsId(const vector<Student> &vec)
{
	vector<string> allStudentGroups;
	for (int i = 0; i < vec.size(); i++)
	{
		allStudentGroups.push_back(vec[i].GroupId);
	}	

	auto p = unique(allStudentGroups.begin(), allStudentGroups.end());
	vector<string> result;
	for (vector<string>::iterator v = allStudentGroups.begin(); v != p; v++)
		result.push_back(*v);
	return result;

}

vector<Group> Groups(const vector<Student> &vec)
{
	vector<Group> result;
	vector<string> groupNames = GroupsId(vec);
	for (int i = 0; i < groupNames.size(); i++)
	{
		Group newGroup;
		vector<Student> studentsInOneGroup;
		newGroup.Id = groupNames[i];
		for (int j = 0; j < vec.size(); j++)
		{
			if (vec[j].GroupId.compare(groupNames[i]) == 0) studentsInOneGroup.push_back(vec[j]);
		}
		newGroup.Students = studentsInOneGroup;
		result.push_back(newGroup);
	}
	return result;
}





int main()
{
	
}


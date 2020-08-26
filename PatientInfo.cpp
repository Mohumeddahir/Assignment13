#include "PatientInfo.hpp"
	using std::string;

// initializes a single counter for all objects.
int PatientInfo::admission_num  = 0;

PatientInfo::PatientInfo(string& lastname, string& firstname, char ward, int room_num) {
	admission_num++;
	m_lastname = lastname;
	m_firstname = firstname;
	m_ward = ward;
	m_room_num = room_num;
	m_id = m_lastname.substr(0,1)+"_"+std::to_string(admission_num);
}

// a nothing constructor
PatientInfo::PatientInfo() 
{}

PatientInfo::PatientInfo(const PatientInfo& copy) {
 	m_id = copy.m_id;
	m_lastname = copy.m_lastname;
	m_firstname = copy.m_firstname;
	m_ward = copy.m_ward;
	m_room_num = copy.m_room_num;
}

PatientInfo::~PatientInfo() {
	// nothing created with 'new' so nothing to deallocate.
}

string PatientInfo::to_string() const{
	return m_id + ": "+m_firstname+" "+m_lastname+" Room number: "
	 	+std::to_string(m_room_num)+m_ward;
}
	
string PatientInfo::get_id() {
	return m_id;
}

string PatientInfo::get_lastname() {
	return m_lastname;
}

string PatientInfo::get_firstname() {
	return m_firstname;
}

void PatientInfo::move(char ward, int room_num) {
	m_ward = ward;
	m_room_num = room_num;
}

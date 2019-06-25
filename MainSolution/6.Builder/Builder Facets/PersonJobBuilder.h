#ifndef _PERSON_JOB_BUILDER_H__
#define _PERSON_JOB_BUILDER_H__

class PersonJobBuilder:public PersonBuilderBase
{
	typedef PersonJobBuilder self;
public:
	PersonJobBuilder(Person& person) :PersonBuilderBase(person) {
	
	}

	self& at(const std::string& company_name) {
		_person._company_name = company_name;
		return *this;
	}
	self& as_a(const std::string& job_title) {
		_person._position = job_title;
		return *this;
	}
	

};

#endif // _PERSON_JOB_BUILDER_H__

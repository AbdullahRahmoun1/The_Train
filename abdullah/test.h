#pragma once
class test
{
public:
	test(void);
	~test(void);
	void sh(){
	soso::myNega();
	test::soso::myNega();
	}
	static class soso{
	public:
		static void myNega(){

		}
	};
};


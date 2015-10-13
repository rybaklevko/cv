/*#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <list>
using namespace std;
class JobRecord{
public:
    JobRecord(const int &mstartyear,const int &mendyear,const std::string &mjobtitle,const std::string &mcompanyname):
        mStartYear(mstartyear),
        mEndYear(mendyear),
        mJobTitle(mjobtitle),
        mCompanyName(mcompanyname)
    {


    }
      bool isValid() const
    {
        return (mStartYear > 1960)
                && (mEndYear > 1960)
                && !mJobTitle.empty()
                && !mCompanyName.empty();
    }

    void print() const
    {
        if (isValid())
        {
            std::cout <<"start:"<< mStartYear << std::endl;
            std::cout <<"end:"<< mEndYear << std::endl;
            std::cout << "Jobtitle: " <<mJobTitle << std::endl;
            std::cout << "Company name: " << mCompanyName << std::endl;
            std::cout << std::endl;
        }
    }
    private:
    int mStartYear;
     int mEndYear;
    std::string mJobTitle;
    std::string mCompanyName;
};
int main()
{
    JobRecord junmicr(1965,2002,"junior","Microsoft");
    JobRecord devsoft(1956,2001,"developer","Softserve");
    JobRecord devapp(1970, 1999, "developer","Apple");
//	std::vector<JobRecord> JbList={junmicr, devsoft,devapp};
    std::array<JobRecord,3>JbList={junmicr,devsoft,devapp};
    //for(auto& jb:JbList)
    for each(const auto& jb in JbList)
    {
        if (jb.isValid())
        {
            jb.print();
        }
        else
        {
            std::cout << "ERROR: jb is invalid" << std::endl;
        }
    }
    system("pause");
    return 0;
}*/
#include <iostream>
#include <string>
#include <array>
#include <vector>

// We should keep list of programmers CVs
// For each CV we have
//      * name field
//      * birthday year
//      * list of skills
//      * list of previous jobs
//      * we would like to print our CV
class JobRecord{
public:
    JobRecord(const int &mstartyear,const int &mendyear,const std::string &mjobtitle,const std::string &mcompanyname):
        mStartYear(mstartyear),
        mEndYear(mendyear),
        mJobTitle(mjobtitle),
        mCompanyName(mcompanyname)
    {


    }
      bool isValid1() const
    {
        return (mStartYear > 1960)
                && (mEndYear > 1960)
                && !mJobTitle.empty()
                && !mCompanyName.empty();
    }

    void print1() const
    {
        if (isValid1())
        {
            std::cout <<"start:"<< mStartYear << std::endl;
            std::cout <<"end:"<< mEndYear << std::endl;
            std::cout << "Jobtitle: " <<mJobTitle << std::endl;
            std::cout << "Company name: " << mCompanyName << std::endl;
            std::cout << std::endl;
        }
    }
    private:
    int mStartYear;
     int mEndYear;
    std::string mJobTitle;
    std::string mCompanyName;
};
class CV
{
public:
    CV(const std::string &name, int birthYear, const std::string &skills, JobRecord previousJobs) :
        mName(name),
        mBirthYear(birthYear)
      , mSkills(skills)
      , mPreviousJobs(previousJobs)
    {

    }
    bool isValid() const
    {
        return !mName.empty()
                && ((mBirthYear > 1963) && (mBirthYear < 1995))
                && !mSkills.empty();
    }

    void print() const
    {
        if (isValid())
        {
            std::cout << mName << " (" << mBirthYear << ")" << std::endl;
            std::cout << "=====================" << std::endl;
            std::cout << "Skills: " << mSkills << std::endl;
            std::cout << std::endl;
        }
    }
    bool jobrecord() const{
        return mPreviousJobs.isValid1();
    }
private:
    std::string mName;
    int mBirthYear;
    std::string mSkills;
    JobRecord mPreviousJobs;
};


int main()
{
    JobRecord junmicr(1965,2002,"junior","Microsoft");
    JobRecord devsoft(1970,2001,"developer","Softserve");
    JobRecord devapp(1970, 1999, "developer","Apple");
    std::array<JobRecord,3>JbList={junmicr,devsoft,devapp};
    //std::vector<JobRecord>JbList(devsoft,junmicr);
    CV johnsCV("John Jonson", 1978,"C++, Java", junmicr);

    CV dansCV("Dan Davidson", 1988, "C++, Java", devsoft);
    CV willCv("Will Walker", 1972, "C++, Java", devapp);

   std::array<CV, 3> cvList ={johnsCV, dansCV,willCv };
    //std::vector<CV> cvList(johnsCV, dansCV);
//   for (const auto& cv: cvList){
  //        for (const auto& jb : JbList)
    for each(const auto& cv in cvList)
        {
        if (cv.isValid()&&cv.jobrecord())
        {
            cv.print();

        }
        else
        {
            std::cout << "ERROR: CV is invalid" << std::endl;
        }
        }
    for each(const auto& jb in JbList){
       if (jb.isValid1())
        {
            jb.print1();
        }
        else
        {
            std::cout << "ERROR: jb is invalid" << std::endl;
        }
    }
    system("pause");
    return 0;
}

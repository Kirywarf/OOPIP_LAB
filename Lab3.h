#ifndef LAB3_H
#define LAB3_H

#include <string>

class Faculty {
protected:
    std::string facultyName;
    int foundationYear;
    std::string specialties;

public:
    Faculty();
    Faculty(const std::string& name, int year, const std::string& spec);
    Faculty(const Faculty& other);
    Faculty& operator=(const Faculty& other);
    virtual ~Faculty();

    void setFacultyName(const std::string& name);
    void setFoundationYear(int year);
    void setSpecialties(const std::string& spec);

    std::string getFacultyName() const;
    int getFoundationYear() const;
    std::string getSpecialties() const;

    virtual void input();
    virtual void print() const;
    virtual double getAverageScore() const;
    virtual std::string getStudyForm() const;
};

class FullTimeStudent : public Faculty {
protected:
    std::string fullName;
    int birthYear;
    double session1;
    double session2;
    double scholarship;

public:
    FullTimeStudent();
    FullTimeStudent(const std::string& faculty, int year, const std::string& spec,
        const std::string& name, int birth,
        double s1, double s2, double st);
    FullTimeStudent(const FullTimeStudent& other);
    FullTimeStudent& operator=(const FullTimeStudent& other);
    virtual ~FullTimeStudent();

    void setFullName(const std::string& name);
    void setBirthYear(int year);
    void setSession1(double value);
    void setSession2(double value);
    void setScholarship(double value);

    std::string getFullName() const;
    int getBirthYear() const;
    double getSession1() const;
    double getSession2() const;
    double getScholarship() const;

    virtual void input();
    virtual void print() const;
    virtual double getAverageScore() const;
    virtual std::string getStudyForm() const;
};

class DistanceStudent : public Faculty {
protected:
    std::string fullName;
    int birthYear;
    double session1;
    double session2;
    double scholarship;

public:
    DistanceStudent();
    DistanceStudent(const std::string& faculty, int year, const std::string& spec,
        const std::string& name, int birth,
        double s1, double s2, double st);
    DistanceStudent(const DistanceStudent& other);
    DistanceStudent& operator=(const DistanceStudent& other);
    virtual ~DistanceStudent();

    void setFullName(const std::string& name);
    void setBirthYear(int year);
    void setSession1(double value);
    void setSession2(double value);
    void setScholarship(double value);

    std::string getFullName() const;
    int getBirthYear() const;
    double getSession1() const;
    double getSession2() const;
    double getScholarship() const;

    virtual void input();
    virtual void print() const;
    virtual double getAverageScore() const;
    virtual std::string getStudyForm() const;
};

void runLab3();

#endif
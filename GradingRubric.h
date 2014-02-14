/*Copyright (c) 2014, Chris Berger, Jesse Freitas, Severin Ibarluzea,
Kiana McNellis, Kienan Knight-Boehm

All rights reserved.
This code is licensed using the BSD "3-Clause" license. Please refer to
"LICENSE.md" for the full license
*/

#include <vector>
#include <string>

#ifndef GRADINGRUBRIC_H_
#define GRADINGRUBRIC_H_

class GradingRubric{
public:

    GradingRubric();

    // ACCESSORS

    int getCompilation() const;
    int getNonHiddenTotal() const;
    int getHiddenTotal() const;
    int getNonHiddenExtraCredit() const;
    int getExtraCredit() const;
    int getTotal() const;
    int getTotalAfterTA() const;

    // PRIVATE VARIABLE ACCESSORS

    int getSubmissionPenalty() const;
    int getNonHiddenReadme() const;
    int getNonHiddenCompilation() const;
    int getHiddenCompilation() const;
    int getHiddenTesting() const;
    int getTAPoints() const;

    // MODIFIERSs

    void setSubmissionPenalty(
            int number_of_submissions,
            int max_submissions,
            int max_penalty);

    void incrREADME(int points, bool hidden);
    void incrCompilation(int points, bool hidden);
    void incrTesting(int points, bool hidden, bool extra_credit);
    void setTA(int points);


    // TEST CASE CODE

    void VerifyTotalAfterTA(int expected_total) const;
    void AddTestCaseResult(bool hidden,
            const std::string & full_message,
            const std::string & hidden_message);
    int NumTestCases() const;
    void GetTestCase(int index, bool & test_case_hidden,
            std::string & test_case_full_messages,
            std::string & test_case_hidden_messages) const;


private:

    // HW Points

    int _nonhidden_readme;
    int _nonhidden_compilation;
    int _nonhidden_testing;
    int _hidden_readme;
    int _hidden_compilation;
    int _hidden_testing;
    int _ta_points;
    int _submission_penalty;
    int _hidden_extra_credit;
    int _nonhidden_extra_credit;

    std::vector<bool> _test_case_hidden;
    std::vector<std::string> _test_case_full_messages;
    std::vector<std::string> _test_case_hidden_messages;

};

#endif

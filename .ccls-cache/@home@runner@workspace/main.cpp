#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

const int NUM_QUESTIONS = 20;
const double PASSING_GRADE = 70.0;


int gradeExam(const std::vector<char>& correctAnswers, const std::vector<char>& studentAnswers, std::vector<int>& missedQuestions);


void writeReport(const std::vector<char>& correctAnswers, const std::vector<char>& studentAnswers, int numMissed, const std::vector<int>& missedQuestions);


int main() {
    
    const std::vector<char> correctAnswers = {'D', 'A', 'B', 'B', 'C', 'A', 'D', 'D', 'A', 'C', 'B', 'D', 'C', 'A', 'A', 'B', 'A', 'C', 'D', 'C'};

    
    const std::vector<char> studentAnswers = {'D', 'A', 'C', 'D', 'C', 'A', 'B', 'D', 'B', 'C', 'B', 'D', 'A', 'A', 'A', 'B', 'A', 'C', 'D', 'C'};

    std::vector<int> missedQuestions;
    int numMissed;

  numMissed = gradeExam(correctAnswers, studentAnswers, missedQuestions);


    writeReport(correctAnswers, studentAnswers, numMissed, missedQuestions);

    return 0;
}

int gradeExam(const std::vector<char>& correctAnswers, const std::vector<char>& studentAnswers, std::vector<int>& missedQuestions) {
    int numMissed = 0;
    missedQuestions.clear();

    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        if (correctAnswers[i] != studentAnswers[i]) {
            numMissed++;
            missedQuestions.push_back(i);
        }
    }
    return numMissed;
}

void writeReport(const std::vector<char>& correctAnswers, const std::vector<char>& studentAnswers, int numMissed, const std::vector<int>& missedQuestions) {
    int numCorrect = NUM_QUESTIONS - numMissed;
    double percentage = (static_cast<double>(numCorrect) / NUM_QUESTIONS) * 100.0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "--------------------------------\n";
    std::cout << "         Exam Report\n";
    std::cout << "--------------------------------\n\n";

    if (missedQuestions.empty()) {
        std::cout << "Congratulations! You did not miss any questions.\n\n";
    } else {
        std::cout << "You missed " << numMissed << " questions.\n\n";
        std::cout << "Questions missed:\n";
        for (int questionIndex : missedQuestions) {
            std::cout << "  Question " << questionIndex + 1 << ":\n";
            std::cout << "    Correct Answer: " << correctAnswers[questionIndex] << "\n";
            std::cout << "    Your Answer:    " << studentAnswers[questionIndex] << "\n";
        }
        std::cout << "\n";
    }

    std::cout << "Total correct answers: " << numCorrect << " out of " << NUM_QUESTIONS << "\n";
    std::cout << "Your score: " << percentage << "%\n";

    if (percentage >= PASSING_GRADE) {
        std::cout << "Result: PASSED\n";
    } else {
        std::cout << "Result: FAILED\n";
    }
    std::cout << "--------------------------------\n";
}
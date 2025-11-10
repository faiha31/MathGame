#include <iostream>
#include <cstdlib>    
#include <ctime>

using namespace std;

enum enQustionsLevel { Easy = 1, Med=2, Hard=3, Mix=4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, OpMix=5 };

struct stQuestion
{
    int Number1=0;
    int Number2=0;
    enOperationType OperationType;
    enQustionsLevel QuestionLevel;
    int CorrectAnswer=0;
    int PlayerAnswer=0;
    bool AnswerResult =false;
    
};
struct stQuizz
{
    stQuestion QuestionList[100];
    int NumberOfQuestion;
    enOperationType OpType;
    enQustionsLevel QustionsLevel;
    int NumberOfRightAnswer=0;
    int NumberOfWrongAnswer=0;
    bool IsPass =false;
};

string GetQustionLevel(enQustionsLevel Level)
{
    string arrLevel[4] = { "Easy", "Med", "Hard", "Mix" };
    return arrLevel[Level - 1];

}
string GetOperationType(enOperationType OpType)
{
    string arrOP[5] = { "+", "-", "*","/", "Mixed" };
    return arrOP[OpType - 1];

}
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;;
}
short ReadHowManyQustions()
{
    short Number;

    do
    {
        cout << "How manu questions do you want to answers ? ";
        cin >> Number;

    } while (Number < 1 || Number > 10);

    return Number;

}
enQustionsLevel ReadQustionLevel()
{
    short QustionLevel;

    do
    {
        cout << "Enter Question Level [1]Easy, [2]Med, [3]Hard, [4]Mix ? ";
        cin >> QustionLevel;

    } while (QustionLevel < 1 || QustionLevel > 4);

    return (enQustionsLevel)QustionLevel;

}
enOperationType ReadQustionOpType()
{
    short QustionOpType;

    do
    {
        cout << "Enter Question Type [1]Add, [2]Sub, [3]Mul, [4]Div, [5]Mix ? ";
        cin >> QustionOpType;

    } while (QustionOpType < 1 || QustionOpType > 5);

    return (enOperationType)QustionOpType;

}
enOperationType  GetRandomOperationType()
{
    return (enOperationType)RandomNumber(1, 4);
}
int SimpleCalculator(int Number1, int Number2, enOperationType  OpType)
{
    switch (OpType)
    {

    case enOperationType::Add:
        return Number1 + Number2;
    case enOperationType::Sub:
        return Number1 - Number2;
    case enOperationType::Mul:
        return Number1 * Number2;
    case enOperationType::Div:
        return (Number2 != 0) ? Number1 / Number2 : 0 ;
    default:
        return Number1 + Number2;


    }

}
stQuestion GeneratQuestion(enQustionsLevel QustionsLevel, enOperationType OpType)
{
    stQuestion Question;

    if (QustionsLevel == enQustionsLevel::Mix)
        QustionsLevel =(enQustionsLevel)RandomNumber(1, 3);
    
    if (OpType == enOperationType::OpMix)
        OpType = GetRandomOperationType();

    Question.OperationType = OpType;

    switch (QustionsLevel)
    {

      case enQustionsLevel::Easy:
      
          Question.Number1 = RandomNumber(1, 10);
          Question.Number2 = RandomNumber(1, 10);
          
          break;
      
      case enQustionsLevel::Med:
      
          Question.Number1 = RandomNumber(10, 50);
          Question.Number2 = RandomNumber(10, 50);
         
          break;
      
      case enQustionsLevel::Hard:
      
          Question.Number1 = RandomNumber(50, 100);
          Question.Number2 = RandomNumber(50, 100);
          
          break;
      
      } 

    Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
    Question.QuestionLevel = QustionsLevel;

    return Question;

}
void GeneratQuizQuestions(stQuizz &Quiz)
{
    for (int QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestion; QuestionNumber++)
        Quiz.QuestionList[QuestionNumber] = GeneratQuestion(Quiz.QustionsLevel, Quiz.OpType);
}
void PrintTheQuestion(stQuizz &Quiz, short QuestionNumber)
{
    cout << "\n\nQuestion [" << QuestionNumber +1 << "/" <<Quiz.NumberOfQuestion<< "]" << endl;
    cout << Quiz.QuestionList[QuestionNumber].Number1 << endl;
    cout << Quiz.QuestionList[QuestionNumber].Number2 << " ";
    cout << GetOperationType(Quiz.QuestionList[QuestionNumber].OperationType) << endl;
    cout << "__________" << endl;

}
int ReadQuestionAnswer()
{
    int Answer;
    cin >> Answer;
    return Answer;

}
void SetScreenColor(bool Result)
{

    if (Result)
        system("color 2F");

    else
    {
        system("color 4F");
        cout << "\a";
    }
       
}
void CorrectQuestionAnswer(stQuizz& Quiz, int QuestionNumber)
{
    if (Quiz.QuestionList[QuestionNumber].PlayerAnswer != Quiz.QuestionList[QuestionNumber].CorrectAnswer)
    {
        Quiz.QuestionList[QuestionNumber].AnswerResult = false;
        Quiz.NumberOfWrongAnswer++;
        cout << "Wrong Answer :( " << endl;
        cout << "The right answer " << Quiz.QuestionList[QuestionNumber].CorrectAnswer << endl;

    }

    else
    {
        Quiz.QuestionList[QuestionNumber].AnswerResult = true;
        Quiz.NumberOfRightAnswer++;
        cout << "Right answer :) " << endl;

    }

    SetScreenColor(Quiz.QuestionList[QuestionNumber].AnswerResult);
}
void AskAndCorrectQuestionAnswer(stQuizz &Quiz)
{

    for (short QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestion; QuestionNumber++)
    {
        PrintTheQuestion(Quiz,QuestionNumber);
        Quiz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
        CorrectQuestionAnswer(Quiz, QuestionNumber);

    }

    Quiz.IsPass=(Quiz.NumberOfRightAnswer >= Quiz.NumberOfWrongAnswer);
}
string GetFinalText(bool Pass)
{
    if (Pass)
        return "Pass :) ";
    else
        return "Fail :( ";
}
string GetLevelText(enQustionsLevel Level)
{
    string arrLevelText[4] = { "Easy ", "Medium", "Hard", "Mixed" };
    return arrLevelText[Level - 1];
}
string GetOpTypeSymbol(enOperationType  OpType)
{
    switch (OpType)
    {

    case enOperationType::Add:
        return "+";
    case enOperationType::Sub:
        return "-";
    case enOperationType::Mul:
        return "*";
    case enOperationType::Div:
        return "/";

    default:
        return "Mix";
    }

}
void PrintQuizResult(stQuizz Quiz)
{
    cout << "\n\n_________________________________________________________" << endl;
    cout << "Final Results is " << GetFinalText(Quiz.IsPass) << endl;
    cout << "_________________________________________________________" << endl;
    cout << "Number of Questions : " << Quiz.NumberOfQuestion << endl;
    cout << "Questions Level : " << GetLevelText(Quiz.QustionsLevel) << endl;
    cout << "OP Type : " << GetOpTypeSymbol(Quiz.OpType) << endl;
    cout << "Number of right answer : " << Quiz.NumberOfRightAnswer << endl;
    cout << "Number of wrong answer : " << Quiz.NumberOfWrongAnswer << endl;

}
void PlayMathGame()
{
    stQuizz Quiz;

    Quiz.NumberOfQuestion = ReadHowManyQustions();
    Quiz.QustionsLevel = ReadQustionLevel();
    Quiz.OpType = ReadQustionOpType();

    GeneratQuizQuestions(Quiz);
    AskAndCorrectQuestionAnswer(Quiz);

    PrintQuizResult(Quiz);
}

void ResetScreen()
{
    system("cls");
    system("Color 0F"); // Black background and White text

}
void StartGame()
{
    char PlayAgain = 'Y';

    do
    {
        ResetScreen();

        PlayMathGame();
        
        cout << endl  << "Do you want to play again ? Y/N ? ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');

}
int main()
{
    srand((unsigned int)time(NULL));

    StartGame();

    return 0;
}


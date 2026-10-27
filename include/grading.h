// include/grading.h
#ifndef GRADING_H
#define GRADING_H

#include <vector>
#include <utility>
#include "constants.h"

/**
 * @brief Calculates one student's mean score across all assignments.
 *
 * @pre studentIndex is in the range [0, STUDENT_COUNT).
 * @post The scores grid is not modified.
 *
 * @param[in] scores        The grade grid.
 * @param[in] studentIndex  Row of the student to average.
 * @return The mean of that student's assignment scores.
 */
[[nodiscard]] double studentAverage(const ScoreGrid& scores,
                                    int studentIndex);

/**
 * @brief Calculates the mean score on one assignment across all students.
 *
 * @pre assignmentIndex is in the range [0, ASSIGNMENT_COUNT).
 * @post The scores grid is not modified.
 *
 * @param[in] scores           The grade grid.
 * @param[in] assignmentIndex  Column of the assignment to average.
 * @return The mean score earned on that assignment.
 */
[[nodiscard]] double assignmentAverage(const ScoreGrid& scores,
                                       int assignmentIndex);

/**
 * @brief Calculates the mean of every score in the grid.
 *
 * @post The scores grid is not modified.
 *
 * @param[in] scores  The grade grid.
 * @return The mean of all STUDENT_COUNT * ASSIGNMENT_COUNT scores.
 */
[[nodiscard]] double classAverage(const ScoreGrid& scores);

/*
 * @brief Finds one student's lowest and highest assignment scores.
 *
 * @pre studentIndex is in the range [0, STUDENT_COUNT).
 * @post lowest holds that student's minimum score.
 * @post highest holds that student's maximum score.
 * @post The scores grid is not modified.
 *
 * @param[in]  scores        The grade grid.
 * @param[in]  studentIndex  Row of the student to examine.
 * @param[out] lowest        Receives the minimum score.
 * @param[out] highest       Receives the maximum score.
 */
void findExtremes(const ScoreGrid& scores, int studentIndex,
                  double& lowest, double& highest);

/**
 * @brief Counts how many students earned a given letter grade.
 *
 * @pre target is one of 'A', 'B', 'C', 'D', or 'F'.
 * @post The scores grid is not modified.
 *
 * @param[in] scores  The grade grid.
 * @param[in] target  The letter grade to count.
 * @return The number of students whose average earns that letter.
 */
[[nodiscard]] int countGrade(const ScoreGrid& scores, char target);

/**
 * @brief Reports whether a student earned a perfect score on any assignment.
 *
 * @pre studentIndex is in the range [0, STUDENT_COUNT).
 * @post The scores grid is not modified.
 *
 * @param[in] scores        The grade grid.
 * @param[in] studentIndex  Row of the student to examine.
 * @return true if any of that student's scores is 100 or above.
 */
[[nodiscard]] bool hasPerfectScore(const ScoreGrid& scores,
                                   int studentIndex);

/**
 * @brief Reports whether a student is academically at risk.
 *
 * A student is at risk when their average is below 70, or when any
 * single assignment score is below 50.
 *
 * @pre studentIndex is in the range [0, STUDENT_COUNT).
 * @post The scores grid is not modified.
 *
 * @param[in] scores        The grade grid.
 * @param[in] studentIndex  Row of the student to examine.
 * @return true if either at-risk condition holds.
 */
[[nodiscard]] bool isAtRisk(const ScoreGrid& scores, int studentIndex);


 /** @brief  Counts the total of students in the class who are acadmically at risk
* @pre None
* @Post The score grid is not modified.
 *
* @param[in] scores the grade grid.
* @return hte total count of students for whom is ATRisk returns true.
 */
 [[nodiscard]] int countAtRisk(const ScoreGrid& scores);
 
 /** @brief finds the higest and lowest  and highest indidivual scores earned acrossed all studewnts and assignments.
 *
 * @pre None
 * @Post lowest holds teh minimum score across teh entire grid .
 *@Post highest holfs the maximum score accoress the entire grid.
 * @post the scores grid is not modified.

 *@param[in] scores the grade grid.
 *@param[out] lowest score  receiveis the overall minimum score.
 *@param[out] highest score  recieved teh overall maxmum score.
 */ 
 void findClassExtremes (const ScoreGrid& scores, double& lowest, double& highest);

/**
* @brief Applies a curve by adding points to all student scores, capping maximum scores at 100.0
*
* @pre STUDENT_COUNT < 0 
* @Post  The scores grid is not modified.
*
*@param[in, out] scores the grade grid to modify.  
*@param[in] points  Points to add to everyoe score.
*@pre points > = 0.0.
*@post Every score increases by points, capped at teh maximum value of 100.0
*/

void applyCurve(ScoreGrid& scores, double points);

/**
* @brief Identidies teh student row index with the highest overall average.
*
*@ pre  STUDENT_COUNT > 0 
*@ POST The  score grid is not modified.
*
*@param[in] scores the grade grid.
*@returns row index in tange [1,STUDENT_COUNT] corresponding to the top top student
*/
[[nodiscard]] int topStudent(const ScoreGrid& scores);




#endif


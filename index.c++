#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string agentName;
    double packOut, packIn, totalCalls;
    int daysInMonth;

    // --- Input monthly numbers ---
    cout << "Agent name: ";
    getline(cin, agentName);

    cout << "Pack Out total: ";
    cin >> packOut;

    cout << "Pack In total: ";
    cin >> packIn;

    cout << "Total number of calls: ";
    cin >> totalCalls;

    cout << "Days in month: ";
    cin >> daysInMonth;

    // Average talk time per call (agent-reported)
    int avgTalkMin, avgTalkSec;
    cout << "Average talk time per call (minutes seconds): ";
    cin >> avgTalkMin >> avgTalkSec;

    // Total talk time for the month (days hours minutes seconds)
    long talkDays, talkHours, talkMinutes, talkSeconds;
    cout << "Total talk time (days hours minutes seconds): ";
    cin >> talkDays >> talkHours >> talkMinutes >> talkSeconds;

    // --- Convert everything to seconds ---
    long totalTalkSec =
        ((talkDays * 24 + talkHours) * 3600) +
        talkMinutes * 60 +
        talkSeconds;
    long inputAvgTalkSec = avgTalkMin * 60 + avgTalkSec;

    // --- Calculations ---
    double weeksInMonth = daysInMonth / 7.0;

    double weeklyPackOut = packOut / weeksInMonth;
    double weeklyPackIn  = packIn  / weeksInMonth;
    double weeklyCalls   = totalCalls / weeksInMonth;
    double weeklyTalkSec = totalTalkSec / weeksInMonth;

    double dailyPackOut  = packOut / daysInMonth;
    double dailyPackIn   = packIn  / daysInMonth;
    double dailyCalls    = totalCalls / daysInMonth;
    double dailyTalkSec  = totalTalkSec / daysInMonth;

    // Average talk time computed from totals
    double calcAvgTalkSec = (totalCalls > 0) ? (totalTalkSec / totalCalls) : 0;

    // Helper to print long durations in hours (can exceed 24)
    auto formatTime = [](double sec) {
        long totalHours = static_cast<long>(sec) / 3600;
        int m = (static_cast<int>(sec) % 3600) / 60;
        int s = static_cast<int>(sec) % 60;
        cout << totalHours << "h " << m << "m " << s << "s";
    };

    auto formatMinSec = [](double sec) {
        int m = static_cast<int>(sec) / 60;
        int s = static_cast<int>(sec) % 60;
        cout << m << "m " << s << "s";
    };

    // --- Output ---
    cout << "\nAgent: " << agentName << "\n";
    cout << fixed << setprecision(2);
    cout << "+------------------+---------+---------+------------+-------------------+\n";
    cout << "| Period           | PackOut | PackIn  | TotalCalls | TotalTalkTime     |\n";
    cout << "+------------------+---------+---------+------------+-------------------+\n";

    cout << "| Monthly          | " << setw(7) << packOut
         << " | " << setw(7) << packIn
         << " | " << setw(10) << totalCalls
         << " | ";
    formatTime(totalTalkSec);
    cout << " |\n";

    cout << "| Weekly  (avg)    | " << setw(7) << weeklyPackOut
         << " | " << setw(7) << weeklyPackIn
         << " | " << setw(10) << weeklyCalls
         << " | ";
    formatTime(weeklyTalkSec);
    cout << " |\n";

    cout << "| Daily   (avg)    | " << setw(7) << dailyPackOut
         << " | " << setw(7) << dailyPackIn
         << " | " << setw(10) << dailyCalls
         << " | ";
    formatTime(dailyTalkSec);
    cout << " |\n";

    cout << "+------------------+---------+---------+------------+-------------------+\n";

    cout << "\nAverage talk time per call (input): ";
    formatMinSec(inputAvgTalkSec);
    cout << "\nAverage talk time per call (calculated): ";
    formatMinSec(calcAvgTalkSec);
    cout << endl;

    return 0;
}

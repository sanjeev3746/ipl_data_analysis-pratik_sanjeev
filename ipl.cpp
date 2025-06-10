//--------------------------------------------------------------------------------------------------

// Header files


#include <iostream>
#include <fstream> // include the file stream library, which allows file manipulation
#include <sstream> // converts string to string stream
#include <vector>
#include <string>
#include <iomanip> // this library we are usign for the data alignment
#include <map> // this library we use for the dictionary kind of thing in c++
#include <ctime> // using for generating random teams in my surprise game
#include <chrono> // to calculate the time and space complexity



//------------------------------------------------------------------------------------------------

// function declaration

std::string displayMainScreen();
std::string dashboard(std::string);
void choose(std::string n);
void merge(std::vector<std::vector<std::string>>& x, int start, int mid, int end, int index);
void mergesort(std::vector<std::vector<std::string>>& x, int start, int end, int index);
void economyMerge(std::vector<std::vector<std::string>>& x, int start, int mid, int end, int index);
void economyMergesort(std::vector<std::vector<std::string>>& x, int start, int end, int index);
int iplDataAnalysis();
std::string yearData(int n);
std::string  batBowlPoints(std::string n);
std::string batting();
std::string bowling();
std::string pointsTable();
void display(std::string n, int year);
void mostRuns(int year);
void mostWickets(int year);
void pointsTableSummary(int year);
void strikeRate(int year);
void economicalFigures(int year);
void top4PointsTable(int year);
void fantasyTeam();
std::vector<std::vector<std::string>> top5Wickets();
std::vector<std::vector<std::string>> top6Runs();
std::vector<std::string> batOutputVector(std::vector<std::string> inputVector1, std::vector<std::string> inputVector2);
std::string teamHub();
void getTeamDetails( int season, const std::string& teamName);
int teamHubYear();
void heroesHub(std::string n);
void getPlayerDetailsBatting(const std::string& playerName);
std::string heroesHubField();
void getPlayerDetailsBowling(const std::string& playerName);
void quickSort(std::vector<std::vector<std::string>>& arr, int low, int high, int index);
int partition(std::vector<std::vector<std::string>>& arr, int low, int high, int index);
std::vector<std::string> split(const std::string& str, char delimiter);
void bucketSort(std::vector<std::vector<std::string>>& arr, int index);
void bucketSorting();
void quickSorting();
void mergeSorting();
std::string algorithms();
void top3Teams(const std::string& fileName);
void insertionSortByRank(std::vector<std::vector<std::string>>& data);
std::map<std::string, int> calculateTeamCounts(const std::string& fileName);
std::pair<std::string, int> chooseComputerTeam(std::map<std::string, int>& teamCounts);
std::pair<std::string, int> getUserTeamChoice(std::map<std::string, int>& teamCounts);
// std::vector<std::vector<std::string>> readCSVFile(const std::string& fileName);
// std::pair<std::string, int> selectTeamBasedOnTime(std::vector<std::pair<std::string, int>>& teams);




//-------------------------------------------------------------------------------------------------



// main function 

int main(){

std::string displayMainScreenOutput = displayMainScreen();
std::string dashboardOutput = dashboard(displayMainScreenOutput);
choose(dashboardOutput);

return 0;

}


//------------------------------------------------------------------------------------------------

// function prototype



void merge(std::vector<std::vector<std::string>>& x, int start, int mid, int end, int index) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    std::vector<std::vector<std::string>> left(n1), right(n2);
    
    for (int i = 0; i < n1; i++) {
        left[i] = x[start + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = x[mid + 1 + i];
    }
    
    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (std::stof(left[i][index]) > std::stof(right[j][index])) {
            x[k] = left[i];
            i++;
        } else {
            x[k] = right[j];
            j++;
        }
        k++;
    }
    
    while (j < n2) {
        x[k] = right[j];
        j++;
        k++;
    }
    
    while (i < n1) {
        x[k] = left[i];
        i++;
        k++;
    }
}

void mergesort(std::vector<std::vector<std::string>>& x, int start, int end, int index) {
    if (start >= end) {
        return;
    }
    int mid = start + (end - start) / 2;
    mergesort(x, start, mid, index);
    mergesort(x, mid + 1, end, index);
    merge(x, start, mid, end, index);
}

void economyMerge(std::vector<std::vector<std::string>>& x, int start, int mid, int end, int index) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    std::vector<std::vector<std::string>> left(n1), right(n2);
    
    for (int i = 0; i < n1; i++) {
        left[i] = x[start + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = x[mid + 1 + i];
    }
    
    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (std::stof(left[i][index]) < std::stof(right[j][index])) {
            x[k] = left[i];
            i++;
        } else {
            x[k] = right[j];
            j++;
        }
        k++;
    }
    
    while (j < n2) {
        x[k] = right[j];
        j++;
        k++;
    }
    
    while (i < n1) {
        x[k] = left[i];
        i++;
        k++;
    }
}

void economyMergesort(std::vector<std::vector<std::string>>& x, int start, int end, int index) {
    if (start >= end) {
        return;
    }
    int mid = start + (end - start) / 2;
    economyMergesort(x, start, mid, index);
    economyMergesort(x, mid + 1, end, index);
    economyMerge(x, start, mid, end, index);
}

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int partition(std::vector<std::vector<std::string>>& arr, int low, int high, int index) {
    std::string pivot = arr[high][index];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (std::stoi(arr[j][index]) > std::stoi(pivot)) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<std::vector<std::string>>& arr, int low, int high, int index) {
    if (low < high) {
        int pi = partition(arr, low, high, index);
        quickSort(arr, low, pi - 1, index);
        quickSort(arr, pi + 1, high, index);
    }
}


void bucketSort(std::vector<std::vector<std::string>>& arr, int index) {
    int n = arr.size();
    std::vector<std::vector<std::vector<std::string>>> buckets(n);

    // Place elements into buckets based on the value at the specified index
    for (const auto& row : arr) {
        // Handle possible parsing error with try-catch
        try {
            int bucketIndex = std::stoi(row[index]);
            // Check if bucketIndex is valid
            if (bucketIndex >= 0 && bucketIndex < n) {
                buckets[bucketIndex].push_back(row);
            } else {
                std::cerr << "Invalid bucket index: " << bucketIndex << std::endl;
            }
        } catch (const std::invalid_argument&) {
            std::cerr << "Error parsing index value: " << row[index] << std::endl;
        }
    }

    // Implement insertion sort for each bucket
    for (auto& bucket : buckets) {
        for (size_t i = 1; i < bucket.size(); ++i) {
            std::vector<std::string> key = bucket[i];
            size_t j = i - 1;
            // Compare and shift elements to sort within the bucket
            while (j < bucket.size() && std::stoi(bucket[j][index]) > std::stoi(key[index])) {
                bucket[j + 1] = bucket[j];
                if (j == 0) break; // Prevent unsigned size_t from underflowing
                j--;
            }
            bucket[j + 1] = key;
        }
    }

    // Concatenate all buckets back to the main array
    int arrIndex = 0;
    for (const auto& bucket : buckets) {
        for (const auto& item : bucket) {
            arr[arrIndex++] = item;
        }
    }
}



std::string displayMainScreen(){

    std::string input;

    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                  TATA IPL              " <<std::endl;                
                  



 std::cout << "                                                 __________" << std::endl;
    std::cout << "                                               '._==_==_=_.'" << std::endl;
    std::cout << "                                               .-\\:      /-." << std::endl;
    std::cout << "                                              | (|:.     |) |" << std::endl;
    std::cout << "                                               '-|:.     |-' " << std::endl;
    std::cout << "                                                 \\::.    /" << std::endl;
    std::cout << "                                                  '::. .'" << std::endl;
    std::cout << "                                                    ) (" << std::endl;
    std::cout << "                                                  _.' '._" << std::endl;
    std::cout << "                                                 `\"\"\"\"\"\"\"`" << std::endl;
    std::cout<<"                              sponsered by PRATIK's AND SANJEEV's SANpro CORP               " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                  !!! WELCOME TO IPL DREAM DASHBOARD !!!                                                        " <<std::endl;                
    std::cout<<"                                                                   " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                               TYPE ipl TO ENTER INTO YOUR DREAM DASHBOARD                            " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl;   
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl;                

    std::cout<<"Type ipl to start your dream journey: "<<std::endl;
    std::cin>>input;


    return input;   
   
}



std::string dashboard(std::string n){
    std::string input;
    if(n == "ipl"){
    std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"!!!WELCOME TO THE IPL DREAM DASHBOARD!!!                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<" 1. IPL DATA ANALYSIS                                              " <<std::endl; 
    std::cout<<" 2. TEAM HUB                                              " <<std::endl; 
    std::cout<<" 3. FANTASY TEAM                                    " <<std::endl; 
    std::cout<<" 4. HEROES HUB                                              " <<std::endl;
    std::cout<<" 5. SURPRISE GAME                                              " <<std::endl; 
    std::cout<<" 6. DIFFERENT ALGORITHM ANALYSIS                                                                 " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;   
     std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl;              
    std::cout<<"==================================================================" <<std::endl;              
    
    std::cout<<"Please type what you want to explore? (in small case including spaces and not extra spaces): "<<std::endl;
    std::cin.get();
    std::getline(std::cin,input);
  
        
    }

    else{
        std::cout<<"Invalid Response!"<<std::endl;

    }
    
    return input;

}


void choose(std::string n){
    int output;
    std::string iplDataAnalysisOutput;
    std::string batBowlPointsOutput;

    if( n == "ipl data analysis"){
        output = iplDataAnalysis();
        iplDataAnalysisOutput = yearData(output);
        batBowlPointsOutput = batBowlPoints(iplDataAnalysisOutput);
        display(batBowlPointsOutput, output);
    }

    else if(n == "fantasy team"){
        fantasyTeam();
    }

    else if(n == "team hub"){
        std::string teamHubOutput;
        int teamHubYearOutput;


        
        teamHubOutput = teamHub();
        teamHubYearOutput = teamHubYear();
        getTeamDetails( teamHubYearOutput, teamHubOutput);  

    }
    

    else if(n == "heroes hub"){
        std::string heroesHubOutput;
        std::string theOutput;


        theOutput = heroesHubField();
         heroesHub(theOutput);
     

    }

    else if(n == "different algorithm analysis"){
        std::string algorithmsOutput;


        algorithmsOutput = algorithms();

        if(algorithmsOutput == "merge sort"){
            mergeSorting();
        }
         else if(algorithmsOutput == "quick sort"){
            quickSorting();
        }
          if(algorithmsOutput == "bucket sort"){
            bucketSorting();
        }

    }

    else if(n == "surprise game"){
        std::string fileName = "points_table.csv"; // Specify the CSV file name

        // Print the top 3 teams for each season from the given CSV file
        top3Teams(fileName);


         // Calculate the count of top 3 teams across all seasons from the CSV file
    std::map<std::string, int> teamCounts = calculateTeamCounts(fileName);


    std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                        !!!LET'S START YOUR SURPRISE GAME!!!                                                             " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"In this game computer will randomly choose one team and you also have to choose one team on the basis of above data.\nALL THE BEST!                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 

    // Computer chooses a team
    std::pair<std::string, int> computerTeam = chooseComputerTeam(teamCounts);
    std::cout << "Computer chose: " << computerTeam.first << " with count: " << computerTeam.second << std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 

    // User chooses a team
    std::pair<std::string, int> userTeam = getUserTeamChoice(teamCounts);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout << "You chose: " << userTeam.first << " with count: " << userTeam.second << std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;

    // Compare the counts and print the winner
    if (computerTeam.second > userTeam.second) {
        std::cout << "Computer's team (" << computerTeam.first << ") wins with a count of " << computerTeam.second << "." << std::endl;
        std::cout<<"Better Luck Next Time! Aren't you RCB fan?"<<std::endl;
         std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
       std::cout<<"==================================================================" <<std::endl; 
    } else if (userTeam.second > computerTeam.second) {
        std::cout << "Your team (" << userTeam.first << ") wins with a count of " << userTeam.second << "." << std::endl;
        std::cout<<"WOW! Your Left Brain is really Developed! You are like CSK fan!"<<std::endl;
           std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
       std::cout<<"==================================================================" <<std::endl; 
    } else {
        std::cout << "It's a tie! Both teams have a count of " << computerTeam.second << "." << std::endl;
        std::cout<<"No Comments!"<<std::endl;
           std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
       std::cout<<"==================================================================" <<std::endl; 
    }

    }


    
    else{
        std::cout<<"Invalid Response!"<<std::endl;
    }
}

// Function to sort a vector of vectors based on rank (column 1)
void insertionSortByRank(std::vector<std::vector<std::string>>& data) {
    for (size_t i = 1; i < data.size(); i++) {
        std::vector<std::string> key = data[i];
        int keyRank = std::stoi(key[1]); // Convert rank to an integer for comparison
        int j = i - 1;

        // Move elements that are greater than keyRank one position ahead
        while (j >= 0 && std::stoi(data[j][1]) > keyRank) {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}


// Function to calculate the count of top 3 teams across all seasons
std::map<std::string, int> calculateTeamCounts(const std::string& fileName) {
    // Read the data from the CSV file
   
   // std::string fileName = "points_table.csv";
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cout << "Failed to open file: " << fileName << std::endl;
    }

    std::vector<std::vector<std::string>> data;
    std::string line;
    
    // Skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string word;
        while (std::getline(ss, word, ',')) {
            row.push_back(word);
        }
        data.push_back(row);
    }

    file.close();

    // Map to store data grouped by season
    std::map<std::string, std::vector<std::vector<std::string>>> seasonMap;

    // Iterate through the data and group by season
    for (const auto& row : data) {
        std::string season = row[0]; // Season is in the first column (index 0)
        // Add the row to the map for the specific season
        seasonMap[season].push_back(row);
    }

    // Calculate team counts
    std::map<std::string, int> teamCounts;

    // Iterate through each season
    for (const auto& seasonData : seasonMap) {
        const std::vector<std::vector<std::string>>& teams = seasonData.second;

        // Make a copy of teams to sort
        std::vector<std::vector<std::string>> sortedTeams = teams;

        // Sort the copied teams based on rank (using insertion sort)
        insertionSortByRank(sortedTeams);

        // Count top 3 teams for the season
        for (int i = 0; i < 3 && i < sortedTeams.size(); i++) {
            const std::vector<std::string>& team = sortedTeams[i];
            teamCounts[team[2]]++; // Increment count for the team
        }
    }

    return teamCounts;
}

// Function to randomly choose a team for the computer from the available team counts
std::pair<std::string, int> chooseComputerTeam(std::map<std::string, int>& teamCounts) {
    // Seed the random number generator
    srand(time(nullptr));

    // Calculate a random index
    size_t randomIndex = rand() % teamCounts.size();

    // Iterate to the randomly selected team
    auto it = teamCounts.begin();
    advance(it, randomIndex);
    std::pair<std::string, int> chosenTeam = *it;

    // Remove the chosen team from the map
    teamCounts.erase(it);

    return chosenTeam;
}

// Function to get user input for choosing a team
std::pair<std::string, int> getUserTeamChoice(std::map<std::string, int>& teamCounts) {
    std::cout << "Available teams:" << std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    int index = 1;
    for (const auto& entry : teamCounts) {
        std::cout << index << ". " << entry.first << " with count: " << entry.second << std::endl;
        index++;
    }

    // Prompt the user to choose a team
    int choice;
    std::cout << "\nEnter the number of the team you want to choose: ";
    std::cin >> choice;

    // Validate user choice
    if (choice < 1 || choice > static_cast<int>(teamCounts.size())) {
        std::cerr << "Invalid choice! Please choose a valid number." << std::endl;
        return getUserTeamChoice(teamCounts);
    }

    // Find the chosen team in the map
    auto it = teamCounts.begin();
    advance(it, choice - 1);
    std::pair<std::string, int> chosenTeam = *it;

    // Remove the chosen team from the map
    teamCounts.erase(it);

    return chosenTeam;
}


// // Function to print the top 3 teams for each season
void top3Teams(const std::string& fileName) {
    // Read the data from the CSV file

    // std::string fileName = "points_table.csv";
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }

    std::vector<std::vector<std::string>> data;
    std::string line;
    
    // Skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string word;
        while (std::getline(ss, word, ',')) {
            row.push_back(word);
        }
        data.push_back(row);
    }

    file.close();


    // Map to store data grouped by season
    std::map<std::string, std::vector<std::vector<std::string>>> seasonMap;
  
    // Iterate through the data and group by season
    for (const auto& row : data) {
        std::string season = row[0]; // Season is in the first column (index 0)
        // Add the row to the map for the specific season
        seasonMap[season].push_back(row);
    }


    std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                      SURPRISE GAME! let's play Logically                                              " <<std::endl;
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"             HERE ARE THE STATS OF TOP 3 TEAMS OF EVERY SEASON ON IPL POINTS TABLE!!!                                             " <<std::endl;
        std::cout<<"                  JUST TRY TO ANALYZE IT AND MAKE A RIGHT DECISION!!!                                                     " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl;
      std::cout<<"                                                                  " <<std::endl;
        std::cout<<"                                                                  " <<std::endl;


    // Iterate through each season in the map
    for (const auto& seasonData : seasonMap) {
        const std::string& season = seasonData.first;
        const std::vector<std::vector<std::string>>& teams = seasonData.second;

        // Make a copy of teams to sort
        std::vector<std::vector<std::string>> sortedTeams = teams;

        // Sort the copied teams based on rank (using insertion sort)
        insertionSortByRank(sortedTeams);

 
    // Iterate through the data and group by season 
        // Print the top 3 teams for the current season
        std::cout << "Season: " << season << std::endl;
     
        for (int i = 0; i < 3 && i < sortedTeams.size(); i++) {
            const std::vector<std::string>& team = sortedTeams[i];
            std::cout << "Team Name: " << team[2] << std::endl;
           
            
        }
         std::cout<<std::endl;
        std::cout<<std::endl;
         std::cout<<"==================================================================" <<std::endl; 
    }
}   


std::string algorithms(){

    std::string input;

    std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"!!!HEY YOU WANT TO TRY DIFFERENT ALGORITHMS ON OUR DATA AND COMPARE THEIR TIME AND SPACE COMPLEXITY ??? !!!                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"  !!! LET'S TRY!!!                                                                " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<" ALGORITHMS ON WHICH YOU CAN TRY:-                                                               " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<" 1. MERGE SORT                                              " <<std::endl; 
    std::cout<<" 2. QUICK SORT                                              " <<std::endl; 
    std::cout<<" 3. BUCKET SORT                                              " <<std::endl;
    std::cout<<"                                                                  " <<std::endl;
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl;                 
    std::cout<<"==================================================================" <<std::endl; 

    std::cout<<"Please type which algorithm you want to explore? (Small case everything, including spaces and no extra spaces): "<<std::endl;
    //std::cin.get();
    std::getline(std::cin,input);

    return input;

}

    //--------------------------------------------------------------------------------

    // MERGESORTING

    void mergeSorting(){

        int index = 3; // Assuming 4th column (0-based indexing)
    std::string fileName = "all_season_batting_card.csv";
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cout << "Failed to open file: " << fileName << std::endl;
    }

    std::vector<std::vector<std::string>> data;
    std::string line;

    // Skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string word;
        while (std::getline(ss, word, ',')) {
            row.push_back(word);
        }
        data.push_back(row);
    }

    auto start = std::chrono::steady_clock::now();

    mergesort(data, 0, data.size() - 1, index);

    auto end = std::chrono::steady_clock::now();
    double sortingTime = std::chrono::duration<double>(end - start).count();

    // Calculate memory usage
    size_t memoryUsage = data.size() * data[0].size() * sizeof(std::string);

    std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                            MERGE SORT                                             " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    // Displaying top 10 highest runs
    std::cout << "TOP 10 HIGHEST RUNS SCORED BY PLAYERS(IN ONE MATCH): ALL OVER [DATA = " << data.size() << " ROWS, " << data[0].size() << " COLUMNS]" << std::endl;
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 

    // Define column widths for proper alignment
    const int seasonWidth = 15;
    const int matchWidth = 20;
    const int playerWidth = 25;
    const int wicketWidth = 10;

    // Print table header with alignment
    std::cout << std::left;
    std::cout << std::setw(seasonWidth) << "Season";
    std::cout << std::setw(matchWidth) << "Match";
    std::cout << std::setw(playerWidth) << "Player";
    std::cout << std::setw(wicketWidth) << "Runs" << std::endl;

    // Print data in tabular format with alignment
    int count = 0;
    for (const auto& row : data) {
        count++;
        if (count > 10) {
            break;
        }
        std::cout << std::left;
        std::cout << std::setw(seasonWidth) << row[0];
        std::cout << std::setw(matchWidth) << row[1];
        std::cout << std::setw(playerWidth) << row[2];
        std::cout << std::setw(wicketWidth) << row[3] << std::endl;
    }

    file.close();
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                        STAT OF MERGE SORT ON OUR DATA                                             " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout << "Time taken for sorting: " << sortingTime << " seconds" << std::endl;
    std::cout << "Space complexity: " << memoryUsage << " bytes" << std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"==================================================================" <<std::endl; 



        

    }

   

    //-----------------------------------------------

// QUICKSORTING


void quickSorting(){

    int index = 3; // Assuming 4th column (0-based indexing)
    std::string fileName = "all_season_batting_card.csv";
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }

    std::vector<std::vector<std::string>> data;
    std::string line;

    // Skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::vector<std::string> row = split(line, ',');
        data.push_back(row);
    }

     auto start = std::chrono::steady_clock::now();

    quickSort(data, 0, data.size() - 1, index);

    auto end = std::chrono::steady_clock::now();
    double sortingTime = std::chrono::duration<double>(end - start).count();

    // Calculate space complexity
    size_t spaceComplexity = data.size() * data[0].size() * sizeof(std::string); // Space for input data

    std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                        QUICK SORT                                           " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    // Displaying top 10 highest runs
    std::cout << "TOP 10 HIGHEST RUNS SCORED BY PLAYERS(IN ONE MATCH): ALL OVER [DATA = " << data.size() << " ROWS, " << data[0].size() << " COLUMNS]" << std::endl;
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl;

    // Define column widths for proper alignment
    const int seasonWidth = 15;
    const int matchWidth = 20;
    const int playerWidth = 25;
    const int wicketWidth = 10;

    // Print table header with alignment
    std::cout << std::left;
    std::cout << std::setw(seasonWidth) << "Season";
    std::cout << std::setw(matchWidth) << "Match";
    std::cout << std::setw(playerWidth) << "Player";
    std::cout << std::setw(wicketWidth) << "Runs" << std::endl;

    // Print data in tabular format with alignment
    int count = 0;
    for (const auto& row : data) {
        count++;
        if (count > 10) {
            break;
        }
        std::cout << std::left;
        std::cout << std::setw(seasonWidth) << row[0];
        std::cout << std::setw(matchWidth) << row[1];
        std::cout << std::setw(playerWidth) << row[2];
        std::cout << std::setw(wicketWidth) << row[3] << std::endl;
    }

    file.close();
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                    STAT OF QUICK SORT ON OUR DATA                                           " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl;
    std::cout << "Time taken for sorting: " << sortingTime << " seconds" << std::endl;
    std::cout << "Space complexity: " << spaceComplexity << " bytes" << std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"==================================================================" <<std::endl; 


    
}


    //-----------------------------------------------

    // BUCKETSORTING


    void bucketSorting(){

    int index = 3; // Assuming 4th column (0-based indexing)
    std::string fileName = "all_season_batting_card.csv";
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }

    std::vector<std::vector<std::string>> data;
    std::string line;

    // Skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::vector<std::string> row = split(line, ',');
        data.push_back(row);
    }

    auto start = std::chrono::steady_clock::now();

    bucketSort(data, index);

    auto end = std::chrono::steady_clock::now();
    double sortingTime = std::chrono::duration<double>(end - start).count();

    // Calculate space complexity
    size_t spaceComplexity = data.size() * data[0].size() * sizeof(std::string); // Space for input data

    std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                          BUCKET SORT                                                     " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    // Displaying top 10 highest runs
    std::cout << "TOP 10 LOWEST RUNS SCORED BY PLAYERS(IN ONE MATCH): ALL OVER [DATA = " << data.size() << " ROWS, " << data[0].size() << " COLUMNS]" << std::endl;
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl;

    // Define column widths for proper alignment
    const int seasonWidth = 15;
    const int matchWidth = 20;
    const int playerWidth = 25;
    const int wicketWidth = 10;

    // Print table header with alignment
    std::cout << std::left;
    std::cout << std::setw(seasonWidth) << "Season";
    std::cout << std::setw(matchWidth) << "Match";
    std::cout << std::setw(playerWidth) << "Player";
    std::cout << std::setw(wicketWidth) << "Runs" << std::endl;

    // Print data in tabular format with alignment
    int count = 0;
    for (const auto& row : data) {
        count++;
        if (count > 10) {
            break;
        }
        std::cout << std::left;
        std::cout << std::setw(seasonWidth) << row[0];
        std::cout << std::setw(matchWidth) << row[1];
        std::cout << std::setw(playerWidth) << row[2];
        std::cout << std::setw(wicketWidth) << row[3] << std::endl;
    }

    file.close();
  std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                       STAT OF BUCKET SORT ON OUR DATA                                                               " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl;
    std::cout << "Time taken for sorting: " << sortingTime << " seconds" << std::endl;
    std::cout << "Space complexity: " << spaceComplexity << " bytes" << std::endl;
       std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"==================================================================" <<std::endl;

    }




std::string heroesHubField(){
    std::string input;

    std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"!!!WELCOME TO THE HEROES HUB, YOUR HERO BELONGS TO WHICH FIELD ??                         " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<" 1. BATTING                                              " <<std::endl; 
    std::cout<<" 2. BOWLING                                              " <<std::endl;  
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"==================================================================" <<std::endl;    

std::cout<<"Please type what you want to explore? (in small case including spaces and not extra spaces): "<<std::endl;

    std::getline(std::cin,input);


  return input;

}


void heroesHub(std::string n){

   std::string input;
    
    if(n == "batting"){

    std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"      !!!WELCOME TO THE IPL HEROES HUB!!!                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"     CHOOSE YOUR FAVOURITE HERO AND SEE HIS ALL STATS FROM 2008 TO 2023                                                            " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<" 1.  MS Dhoni                                             " <<std::endl;
    std::cout<<"                                                                  " <<std::endl;  
    std::cout<<" 2.  Ravindra Jadeja                                           " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 3.  Chris Gayle                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 4.  Suresh Raina                                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 5.  Rohit Sharma                                            " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 6.  AB de Villiers                                             " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 7.  Virat Kohli                                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl;  
    std::cout<<" 8.  Brendon McCullum                           " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 9.  KL Rahul                                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 10. Yuvraj Singh                                            " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 11. Kieron Pollard                             " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 12. David Warner                                         " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 13. Steven Smith                                            " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 14. Faf du Plessis                                              " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 15. Andre Russell                                             " <<std::endl;       
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"==================================================================" <<std::endl;              
    
    std::cout<<"Please type the name of your favourite heroto watch his brilliants stats from 2008 to 2023 (Only player name, Capitalization as mentioned in Display!): "<<std::endl;
    //std::cin.get();
    std::getline(std::cin,input);
    
    getPlayerDetailsBatting(input);
  
    }

    else if( n == "bowling"){

std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"      !!!WELCOME TO THE IPL HEROES HUB!!!                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"     CHOOSE YOUR FAVOURITE HERO AND SEE HIS ALL STATS FROM 2008 TO 2023                                                            " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<" 1.  Bhuvneshwar Kumar                                             " <<std::endl;
    std::cout<<"                                                                  " <<std::endl;  
    std::cout<<" 2.  Jasprit Bumrah                                           " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 3.  Sunil Narine                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 4.  Ravichandran Ashwin                                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 5.  Mitchell Johnson                                            " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 6.  Mitchell Starc                                             " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 7.  Trent Boult                                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl;  
    std::cout<<" 8.  Dale Steyn                           " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 9.  Lasith Malinga                                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 10. Amit Mishra,                                            " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 11. Mohammed Shami                             " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 12. Mohit Sharma                                         " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 13. Yuzvendra Chahal                                           " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 14. Dwayne Bravo                                              " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 15. Ashish Nehra                                             " <<std::endl;       
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"==================================================================" <<std::endl;              
    
    std::cout<<"Please type the name of your favourite heroto watch his brilliants stats from 2008 to 2023 (Only player name, Capitalization as mentioned in Display!): "<<std::endl;
    //std::cin.get();
    std::getline(std::cin,input);

     getPlayerDetailsBowling(input);
  
    }
        
    else{
        std::cout<<"Invalid Response!"<<std::endl;
    }
    


    
}

void getPlayerDetailsBatting(const std::string& playerName) {
    // Vector to store all data rows from the CSV file
    std::string fileName = "all_season_batting_card.csv";
    std::vector<std::vector<std::string>> data;
    
    // Open the CSV file
    std::ifstream file(fileName);
    
    // Check if the file is opened
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }
    
    std::string line;
    // Skip the header line if the file contains one
    std::getline(file, line);
    
    // Read each line from the file
    while (std::getline(file, line)) {
        // Parse the line and split it by commas
        std::stringstream ss(line);
        std::string word;
        std::vector<std::string> row;
        while (std::getline(ss, word, ',')) {
            row.push_back(word);
        }
        // Store the row in the data vector
        data.push_back(row);
    }
    
    // Close the file
    file.close();
    
    bool playerFound = false;
    
    // Iterate through the data vector to find the specified player
  std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"      !!!WELCOME TO THE IPL HEROES HUB!!!                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"     YOUR FAVOURITE HERO'S STAT FROM 2008 TO 2023, WATCH IT AND ENJOY!!!                                                        " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;   
  std::cout<< "Season";
    std::cout<< "       Match";
    std::cout<< "              Player";
    std::cout << "                   Runs";
    std::cout << "            Strike Rate";
    std::cout<<std::endl;
    for (const auto& row : data) {
        std::string fullName = row[2]; // Full name of the player (column index 2)

        // Check if the current row matches the specified player name
        if (fullName == playerName) {
            // If a match is found, output all the details of the player in a horizontal tabular format
            std::cout << std::left;
            std::cout << std::setw(10) << row[0] << std::setw(20) << row[1] << std::setw(28) << row[2] << std::setw(15) << row[3] << std::setw(2) << row[4] << std::endl;
            playerFound = true;
        }
    }
    
    if (!playerFound) {
        std::cout << "No data found for player: " << playerName << std::endl;
    }
}

void getPlayerDetailsBowling(const std::string& playerName) {
    // Vector to store all data rows from the CSV file
    std::string fileName = "all_season_bowling_card.csv";
    std::vector<std::vector<std::string>> data;
    
    // Open the CSV file
    std::ifstream file(fileName);
    
    // Check if the file is opened
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }
    
    std::string line;
    // Skip the header line if the file contains one
    std::getline(file, line);
    
    // Read each line from the file
    while (std::getline(file, line)) {
        // Parse the line and split it by commas
        std::stringstream ss(line);
        std::string word;
        std::vector<std::string> row;
        while (std::getline(ss, word, ',')) {
            row.push_back(word);
        }
        // Store the row in the data vector
        data.push_back(row);
    }
    
    // Close the file
    file.close();
    
    bool playerFound = false;
    
    // Iterate through the data vector to find the specified player
    std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"      !!!WELCOME TO THE IPL HEROES HUB!!!                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"     YOUR FAVOURITE HERO'S STAT FROM 2008 TO 2023, WATCH IT AND ENJOY!!!                                                        " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;   
  std::cout<< "Season";
    std::cout<< "       Match";
    std::cout<< "              Player";
    std::cout << "                   Wickets";
    std::cout << "            Economy Rate";
    std::cout<<std::endl;
    for (const auto& row : data) {
        std::string fullName = row[2]; // Full name of the player (column index 2)

        // Check if the current row matches the specified player name
        if (fullName == playerName) {
            // If a match is found, output all the details of the player in a horizontal tabular format
            std::cout << std::left;
            std::cout << std::setw(10) << row[0] << std::setw(20) << row[1] << std::setw(28) << row[2] << std::setw(15) << row[5] << std::setw(2) << row[6] << std::endl;
            playerFound = true;
        }
    }
    
    if (!playerFound) {
        std::cout << "No data found for player: " << playerName << std::endl;
    }
}




std::string teamHub(){

     std::string input;
    
    std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"      !!!WELCOME TO THE IPL TEAM HUB!!!                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<" 1.  Chennal Super Kings  (2008 - 2023)                                             " <<std::endl;
    std::cout<<"                                                                  " <<std::endl;  
    std::cout<<" 2.  Mumbai Indians  (2008 - 2023)                                             " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 3.  Royal Challengers Bangalore  (2008 - 2023)                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 4.  Rajasthan Royals  (2008 - 2023)                                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 5.  Gujarat Titans  (2022 - 2023)                                            " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 6.  Sunrisers Hyderabad (2013 - 2023)                                             " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 7.  Kings XI Punjab  (2008 - 2023)                                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl;  
    std::cout<<" 8.  Lucknow Super Giants   (2022 - 2023)                            " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 9.  Kolkata Knight Riders  (2008 - 2023)                                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 10. Kochi Tuskers  (2011 ONLY)                                             " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 11. Delhi Capitals  (2008 - 2023)                              " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 12. Pune Warriors   (2011 - 2013)                                         " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 13. Rising Pune Supergiant  (2016 - 2017)                                            " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 14. Deccan Chargers  (2008 - 2012)                                              " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<" 15. Punjab Kings  (2021 - 2023)                                              " <<std::endl;       
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"==================================================================" <<std::endl;              
    
    std::cout<<"Please type which team status you want to explore? (Only team name, Capitalization as mentioned in Display!): "<<std::endl;
    //std::cin.get();
    std::getline(std::cin,input);
  
        

    
    return input;

}



int teamHubYear(){
    int input;
    

    std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"!!!WELCOME TO THE IPL DATA ANALYSIS!!!                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<" 1.  YEAR 2008                                              " <<std::endl; 
    std::cout<<" 2.  YEAR 2009                                              " <<std::endl; 
    std::cout<<" 3.  YEAR 2010                                              " <<std::endl; 
    std::cout<<" 4.  YEAR 2011                                              " <<std::endl; 
    std::cout<<" 5.  YEAR 2012                                              " <<std::endl; 
    std::cout<<" 6.  YEAR 2013                                              " <<std::endl; 
    std::cout<<" 7.  YEAR 2014                                              " <<std::endl; 
    std::cout<<" 8.  YEAR 2015                                              " <<std::endl; 
    std::cout<<" 9.  YEAR 2016                                              " <<std::endl; 
    std::cout<<" 10. YEAR 2017                                              " <<std::endl; 
    std::cout<<" 11. YEAR 2018                                              " <<std::endl;  
    std::cout<<" 12. YEAR 2019                                              " <<std::endl; 
    std::cout<<" 13. YEAR 2020                                              " <<std::endl; 
    std::cout<<" 14. YEAR 2021                                              " <<std::endl; 
    std::cout<<" 15. YEAR 2022                                              " <<std::endl; 
    std::cout<<" 16. YEAR 2023                                              " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;   
    std::cout<<"                                                                  " <<std::endl;
    std::cout<<"                                                                  " <<std::endl;             
    std::cout<<"==================================================================" <<std::endl;              
    
    std::cout<<"Please enter THE YEAR YOU WANT TO EXPLORE(press 2008 to 2023 in numbers and don't leave extra spaces): "<<std::endl;
    std::cin>>input;
        
    

  

    return input;
}


int iplDataAnalysis(){
    int input;
    

    std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"!!!WELCOME TO THE IPL DATA ANALYSIS!!!                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<" 1.  YEAR 2008                                              " <<std::endl; 
    std::cout<<" 2.  YEAR 2009                                              " <<std::endl; 
    std::cout<<" 3.  YEAR 2010                                              " <<std::endl; 
    std::cout<<" 4.  YEAR 2011                                              " <<std::endl; 
    std::cout<<" 5.  YEAR 2012                                              " <<std::endl; 
    std::cout<<" 6.  YEAR 2013                                              " <<std::endl; 
    std::cout<<" 7.  YEAR 2014                                              " <<std::endl; 
    std::cout<<" 8.  YEAR 2015                                              " <<std::endl; 
    std::cout<<" 9.  YEAR 2016                                              " <<std::endl; 
    std::cout<<" 10. YEAR 2017                                              " <<std::endl; 
    std::cout<<" 11. YEAR 2018                                              " <<std::endl;  
    std::cout<<" 12. YEAR 2019                                              " <<std::endl; 
    std::cout<<" 13. YEAR 2020                                              " <<std::endl; 
    std::cout<<" 14. YEAR 2021                                              " <<std::endl; 
    std::cout<<" 15. YEAR 2022                                              " <<std::endl; 
    std::cout<<" 16. YEAR 2023                                              " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;   
    std::cout<<"                                                                  " <<std::endl;
    std::cout<<"                                                                  " <<std::endl;             
    std::cout<<"==================================================================" <<std::endl;              
    
    std::cout<<"Please enter THE YEAR YOU WANT TO EXPLORE(press 2008 to 2023 in numbers and don't leave extra spaces): "<<std::endl;
    std::cin>>input;
        
    

  

    return input;
}


std::string yearData(int n){

    std::string input;

    if(n >= 2008 && n <= 2023){


    std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"!!!WELCOME TO THE IPL DATA ANALYSIS!!!                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<" 1.  Batting                                               " <<std::endl; 
    std::cout<<" 2.  Bowling                                               " <<std::endl; 
    std::cout<<" 3.  Points Table                                               " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;   
    std::cout<<"                                                                  " <<std::endl;
    std::cout<<"                                                                  " <<std::endl;             
    std::cout<<"==================================================================" <<std::endl;              
    
    std::cout<<"Please enter THE AREA YOU WANT TO EXPLORE(Type your choice in small case including spaces and not extra spaces): "<<std::endl;
    std::cin.get();
    std::getline(std::cin,input);

    }
        

    else{
        std::cout<<"Invalid Response!"<<std::endl;
    }

    return input;


}

std::string  batBowlPoints(std::string n){
    std::string output;

    if(n == "batting"){
        output = batting();
    }
    else if(n == "bowling"){
        output = bowling();
    }
    else if(n == "points table"){
        output = pointsTable();
    }


    else{
           std::cout<<"Invalid Response!"<<std::endl;

    }

    return output;
}



std::string batting(){

     std::string input;


    std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"!!!WELCOME TO THE IPL DATA ANALYSIS!!!                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<" 1.  Most Runs                                             " <<std::endl; 
    std::cout<<" 2.  Highest Strike Rate                                               " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;   
    std::cout<<"                                                                  " <<std::endl;
    std::cout<<"                                                                  " <<std::endl;             
    std::cout<<"==================================================================" <<std::endl;              
    
    std::cout<<"Please enter THE AREA YOU WANT TO EXPLORE(Type your choice in small case including spaces and not extra spaces): "<<std::endl;

    std::getline(std::cin,input);

    return input;

}


std::string bowling(){

     std::string input;


    std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"!!!WELCOME TO THE IPL DATA ANALYSIS!!!                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<" 1.  Most Wickets                                             " <<std::endl; 
    std::cout<<" 2.  Most Economical Figures                                               " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;   
    std::cout<<"                                                                  " <<std::endl;
    std::cout<<"                                                                  " <<std::endl;             
    std::cout<<"==================================================================" <<std::endl;              
    
    std::cout<<"Please enter THE AREA YOU WANT TO EXPLORE(Type your choice in small case including spaces and not extra spaces): "<<std::endl;

    std::getline(std::cin,input);

    return input;

}

std::string pointsTable(){

     std::string input;


    std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"!!!WELCOME TO THE IPL DATA ANALYSIS!!!                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<" 1.  Points Table Summary                                             " <<std::endl; 
    std::cout<<" 2.  Top 4 Teams in Points Table                                               " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;   
    std::cout<<"                                                                  " <<std::endl;
    std::cout<<"                                                                  " <<std::endl;             
    std::cout<<"==================================================================" <<std::endl;              
    
    std::cout<<"Please enter THE AREA YOU WANT TO EXPLORE(Type your choice in small case including spaces and not extra spaces): "<<std::endl;
    //std::cin.get();
    std::getline(std::cin,input);
  
    

    return input;

}


void display(std::string n, int year){

    
    if(n == "most runs"){
        mostRuns(year);
    }
    else if(n == "most wickets"){
        mostWickets(year);
    }
     else if(n == "points table summary"){
        pointsTableSummary(year);
    }
    else if(n == "highest strike rate"){
        strikeRate(year);
    }
    else if(n == "most economical figures"){
        economicalFigures(year);
    }
    else if(n == "top 4 teams in points table"){
        top4PointsTable(year);
    }

   else{
        std::cout<<"Invalid Response!"<<std::endl;
        
    } 
}




void mostRuns(int year){
    int index = 3;

    std::cout << "==================================================================" << std::endl;
    std::cout << "                                                                  " << std::endl;
    std::cout << "                                                                  " << std::endl;
    std::cout << "TOP 10 HIGHEST RUNS SCORED BY PLAYERS(IN ONE MATCH) OF: " << year << std::endl;
    std::cout << "                                                                  " << std::endl;
    std::cout << "                                                                  " << std::endl;

    std::string fileName = std::to_string(year) + "batting.csv";
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }

    std::vector<std::vector<std::string>> data;
    std::string line;
    
    // Skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string word;
        while (std::getline(ss, word, ',')) {
            row.push_back(word);
        }
        data.push_back(row);
    }

    mergesort(data, 0, data.size() - 1, index);

    // Define column widths for proper alignment
    const int seasonWidth = 15;
    const int matchWidth = 20;
    const int playerWidth = 25;
    const int wicketWidth = 10;

    // Print table header with alignment
    std::cout << std::left;
    std::cout          << std::setw(seasonWidth) << "Season";
    std::cout          << std::setw(matchWidth) << "Match";
    std::cout          << std::setw(playerWidth) << "Player";
    std::cout          << std::setw(wicketWidth) << "Runs";
    std::cout          << std::endl;

    // Print data in tabular format with alignment
    int count = 0;
    for (const auto& row : data) {
        count++;
        if (count > 10) {
            break;
        }
        std::cout << std::left;
        std::cout          << std::setw(seasonWidth) << row[0];
        std::cout          << std::setw(matchWidth) << row[1];
        std::cout          << std::setw(playerWidth) << row[2];
        std::cout          << std::setw(wicketWidth) << row[3];
        std::cout          << std::endl;
    }

    file.close();

    std::cout << "                                                                  " << std::endl;
    std::cout << "                                                                  " << std::endl;
    std::cout << "==================================================================" << std::endl;

    
    

}
   

void mostWickets(int year){

    int index = 5;

    std::cout << "==================================================================" << std::endl;
    std::cout << "                                                                  " << std::endl;
    std::cout << "                                                                  " << std::endl;
    std::cout << "TOP 10 WICKET TAKERS IN(ONE MATCH) OF: " << year << std::endl;
    std::cout << "                                                                  " << std::endl;
    std::cout << "                                                                  " << std::endl;

    std::string fileName = std::to_string(year) + "bowling.csv";
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }

    std::vector<std::vector<std::string>> data;
    std::string line;
    
    // Skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string word;
        while (std::getline(ss, word, ',')) {
            row.push_back(word);
        }
        data.push_back(row);
    }
    mergesort(data, 0, data.size() - 1, index );

    // Define column widths for proper alignment
    const int seasonWidth = 15;
    const int matchWidth = 20;
    const int playerWidth = 25;
    const int wicketWidth = 10;

    // Print table header with alignment
    std::cout << std::left;
    std::cout          << std::setw(seasonWidth) << "Season";
    std::cout          << std::setw(matchWidth) << "Match";
    std::cout          << std::setw(playerWidth) << "Player";
    std::cout          << std::setw(wicketWidth) << "Wickets";
    std::cout          << std::endl;

    // Print data in tabular format with alignment
    int count = 0;
    for (const auto& row : data) {
        count++;
        if (count > 10) {
            break;
        }
        std::cout << std::left;
        std::cout          << std::setw(seasonWidth) << row[0];
        std::cout          << std::setw(matchWidth) << row[1];
        std::cout          << std::setw(playerWidth) << row[2];
        std::cout          << std::setw(wicketWidth) << row[5];
        std::cout          << std::endl;
    }

    file.close();

    std::cout << "                                                                  " << std::endl;
    std::cout << "                                                                  " << std::endl;
    std::cout << "==================================================================" << std::endl;

    
    
}
void pointsTableSummary(int year){

    std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"POINTS TABLE SUMMARY OF: "<< year<<std::endl;
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 

   
    std::string fileName = std::to_string(year) + "points.csv";

    std::ifstream file(fileName); // Use ifstream for input
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        
    }

    std::vector<std::vector<std::string>> data;
    std::string line;
    // Read header and discard it
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string word;
        while (std::getline(ss, word, ',')) {
            row.push_back(word);
        }
        data.push_back(row);
    }
    
    // Print table header
    std::cout << "Season  Rank    Team  Matches   Won    Lost    Points" << std::endl;

    // Print data in tabular format
    for (const auto& row : data) {
        for (const auto& cell : row) {
            std::cout << cell << "\t";
        }
        std::cout << std::endl;
    }

    file.close();

    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"==================================================================" <<std::endl;


    
 
}

void strikeRate(int year){

    int index = 5;

    std::cout << "==================================================================" << std::endl;
    std::cout << "                                                                  " << std::endl;
    std::cout << "                                                                  " << std::endl;
    std::cout << "TOP 10 HIGHEST STRIKE RATE BY PLAYERS IN(ONE MATCH) OF: " << year << std::endl;
    std::cout << "                                                                  " << std::endl;
    std::cout << "                                                                  " << std::endl;

    std::string fileName = std::to_string(year) + "batting.csv";
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }

    std::vector<std::vector<std::string>> data;
    std::string line;
    
    // Skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string word;
        while (std::getline(ss, word, ',')) {
            row.push_back(word);
        }
        data.push_back(row);
    }

   
    mergesort(data, 0, data.size() - 1, index);

    // Define column widths for proper alignment
    const int seasonWidth = 10;
    const int matchWidth = 20;
    const int playerWidth = 25;
    const int wicketWidth = 4;

    // Print table header with alignment
    std::cout << std::left;
    std::cout          << std::setw(seasonWidth) << "Season";
    std::cout          << std::setw(matchWidth) << "Match";
    std::cout          << std::setw(playerWidth) << "Player";
    std::cout          << std::setw(wicketWidth) << "Strike Rate";
    std::cout          << std::endl;
    
    // Print data in tabular format with alignment
    int count = 0;
    for (const auto& row : data) {
        count++;
        if (count > 10) {
            break;
        }




        std::cout << std::left;
        std::cout          << std::setw(seasonWidth) << row[0];
        std::cout          << std::setw(matchWidth) << row[1];
        std::cout          << std::setw(playerWidth) << row[2];
        std::cout          << std::setw(wicketWidth) << row[5];
        std::cout          << std::endl;
    }

    file.close();

    std::cout << "                                                                  " << std::endl;
    std::cout << "                                                                  " << std::endl;
    std::cout << "==================================================================" << std::endl;

    
    
}

void economicalFigures(int year){

    int index = 6;

    std::cout << "==================================================================" << std::endl;
    std::cout << "                                                                  " << std::endl;
    std::cout << "                                                                  " << std::endl;
    std::cout << "TOP 10 ECONOMICAL FIGURES(IN ONE MATCH) OF: " << year << std::endl;
    std::cout << "                                                                  " << std::endl;
    std::cout << "                                                                  " << std::endl;

    std::string fileName = std::to_string(year) + "bowling.csv";
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }

    std::vector<std::vector<std::string>> data;
    std::string line;
    
    // Skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string word;
        while (std::getline(ss, word, ',')) {
            row.push_back(word);
        }
        data.push_back(row);
    }

    economyMergesort(data, 0, data.size() - 1, index );

    // Define column widths for proper alignment
    const int seasonWidth = 10;
    const int matchWidth = 20;
    const int playerWidth = 25;
    const int wicketWidth = 2;

    // Print table header with alignment
    std::cout << std::left;
    std::cout          << std::setw(seasonWidth) << "Season";
    std::cout          << std::setw(matchWidth) << "Match";
    std::cout          << std::setw(playerWidth) << "Player";
    std::cout          << std::setw(wicketWidth) << "Economy Rate";
    std::cout          << std::endl;

    // Print data in tabular format with alignment
    int count = 0;
    for (const auto& row : data) {
        count++;
        if (count > 10) {
            break;
        }
        std::cout << std::left;
        std::cout          << std::setw(seasonWidth) << row[0];
        std::cout          << std::setw(matchWidth) << row[1];
        std::cout          << std::setw(playerWidth) << row[2];
        std::cout          << std::setw(wicketWidth) << row[6];
        std::cout          << std::endl;
    }

    file.close();

    std::cout << "                                                                  " << std::endl;
    std::cout << "                                                                  " << std::endl;
    std::cout << "==================================================================" << std::endl;


    
}
void top4PointsTable(int year){

    std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"TOP 4 TEAMS IN POINTS TABLE OF: "<<year<<std::endl;
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 

  std::string fileName = std::to_string(year) + "points.csv";

     std::ifstream file(fileName); // Use ifstream for input
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }

    std::vector<std::vector<std::string>> data;
    std::string line;
    // Read header and discard it
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string word;
        while (std::getline(ss, word, ',')) {
            row.push_back(word);
        }
        data.push_back(row);
    }

    file.close();

    // Print table header
    std::cout << "Season  Rank    Team  Matches   Won    Lost    Points" << std::endl;

    // Print data in tabular format
    for (const auto& row : data) {
        int rank = std::stoi(row[1]); // Convert rank to integer
        if (rank <= 4) { // Print teams up to 4th rank
            for (const auto& cell : row) {
                std::cout << cell << "\t";
            }
            std::cout << std::endl;
        }
    }
    

    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"==================================================================" <<std::endl;
    
}


void fantasyTeam() {
    std::vector<std::vector<std::string>> top5WicketsOutput = top5Wickets();
    std::vector<std::vector<std::string>> top6BatsmenOutput = top6Runs();

    std::cout << "==================================================================" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(72) << std::left << " !!!WELCOME TO THE IPL FANTASY TEAM!!! " << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(72) << std::left << "EXPERT ADVICE:- Here in this section:-  \nWe sorted the data of past 16 years \nBatting = Runs sort \nBowling = Wickets sort" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(72) << std::left << "BY SORTING ALL OF THEM WE MADE A FANTASY TEAM OF IPL, SO COME ON GUYS! CHOOSE OUR TEAM, AND BET ON DREAM 11, AND WIN 7 CRORE!!!" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(72) << std::left << "THANKS US LATER!!!" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
        std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(67) << std::left << "                   IPL FANTASY TEAM OF DREAM 11" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << " BATSMEN" << std::endl;
     std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(28) << std::left << "PLAYER NAME" << std::setw(10) << std::left << "RUNS" << std::setw(20) << std::left << "FANTASY POINTS" << std::endl;
    for (int i = 0; i < 6 && i < top6BatsmenOutput.size(); i++) {
        std::cout << std::setw(28) << std::left << top6BatsmenOutput[i][0] << std::setw(10) << std::left << top6BatsmenOutput[i][1] << std::setw(20) << std::left << top6BatsmenOutput[i][2] << std::endl;
    }

    std::cout << std::endl;
        std::cout << std::endl;
    std::cout << std::endl;
        std::cout << std::endl;
    std::cout << std::endl;
    std::cout << " BOWLERS" << std::endl;
     std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(28) << std::left << "PLAYER NAME" << std::setw(10) << std::left << "WICKETS" << std::setw(20) << std::left << "FANTASY POINTS" << std::endl;
    for (int i = 0; i < 5 && i < top5WicketsOutput.size(); i++) {
        std::cout << std::setw(28) << std::left << top5WicketsOutput[i][0] << std::setw(10) << std::left << top5WicketsOutput[i][1] << std::setw(20) << std::left << top5WicketsOutput[i][2] << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "==================================================================" << std::endl;
}



std::vector<std::vector<std::string>> top5Wickets(){

    int index = 5;

    std::string fileName = "all_season_bowling_card.csv";
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        //return;
    }

    std::vector<std::vector<std::string>> data;
    std::string line;
    
    // Skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string word;
        while (std::getline(ss, word, ',')) {
            row.push_back(word);
        }
        data.push_back(row);
    }

    mergesort(data, 0, data.size() - 1, index);

    // Print data in tabular format with alignment
    int count = 0;
    std::vector<std::vector<std::string>> top5WicketsVector;
    
    for (const auto& row : data) {
        count++;
        if (count > 5) {
            break;
        }
     top5WicketsVector.push_back({row[2],row[5],row[5]+"00"});
        
    }

    file.close();

    return top5WicketsVector;

}






std::vector<std::vector<std::string>> top6Runs(){

    int index = 3;

    std::string fileName = "all_season_batting_card.csv";
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        //return;
    }

    std::vector<std::vector<std::string>> data;
    std::string line;
    
    // Skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string word;
        while (std::getline(ss, word, ',')) {
            row.push_back(word);
        }
        data.push_back(row);
    }

    mergesort(data, 0, data.size() - 1, index);

    // Print data in tabular format with alignment
    int count = 0;
   std::vector<std::vector<std::string>>  top6RunsVector;
    
    for (const auto& row : data) {
        count++;
        if (count > 6) {
            break;
        }

            top6RunsVector.push_back({row[2],row[3],row[3] + "0"});
        

    }

    file.close();

    return top6RunsVector;

}



void getTeamDetails( int season, const std::string& teamName) {

    std::string fileName = "points_table.csv";
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }

    std::string line;
    // Skip the header line if the file contains one
    std::getline(file, line);

    bool teamFound = false;

    std::cout<<"==================================================================" <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;                
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"      !!!WELCOME TO THE IPL TEAM HUB!!!                          " <<std::endl;
    std::cout<<"                                                                  " <<std::endl; 
    std::cout<<"                                                                  " <<std::endl;

    // Read each line from the file
    while (std::getline(file, line)) {
        // Parse the line and split it by commas
        std::stringstream ss(line);
        std::string word;
        std::vector<std::string> row;
        while (std::getline(ss, word, ',')) {
            row.push_back(word);
        }

        // Assuming the columns are:
        // season, rank, name, matchesplayed, matcheswon, matcheslost, matchpoints

        // Parse the data types from strings
        int fileSeason = std::stoi(row[0]); // season (column index 0)
        std::string fileTeamName = row[2]; // name (column index 2)

        // Check if the current row matches the specified season and team name
        if (fileSeason == season && fileTeamName == teamName) {
            // If a match is found, output all the details of the team
            std::cout << "Details of season: " << season << ", Team: " << teamName << std::endl;

         std::cout<<"                                                                  " <<std::endl;                
        std::cout<<"                                                                  " <<std::endl; 
         std::cout<<"                                                                  " <<std::endl;                
        std::cout<<"                                                                  " <<std::endl; 
            std::cout << "Rank: " << row[1] << std::endl;
            std::cout << "Matches Played: " << row[3] << std::endl;
            std::cout << "Matches Won: " << row[4] << std::endl;
            std::cout << "Matches Lost: " << row[5] << std::endl;
            std::cout << "Match Points: " << row[6] << std::endl;
            std::cout<<"                                                                  " <<std::endl;                
        std::cout<<"                                                                  " <<std::endl; 
        std::cout<<"                                                                  " <<std::endl;                
        std::cout<<"                                                                  " <<std::endl; 
          std::cout<<"==================================================================" <<std::endl; 
            teamFound = true;

            break; // Exit the loop once the data is found
        }
    }

    if (!teamFound) {
        std::cout<<"==================================================================" <<std::endl;
        std::cout<<"                                                                  " <<std::endl; 
        std::cout<<"                                                                  " <<std::endl;
        std::cout << "No data found for season " << season << " and team " << teamName << "." << std::endl;
        std::cout<<"Just look at instructions on team page, You may given wrong year or team name."<<std::endl;
        std::cout<<"                                                                  " <<std::endl; 
        std::cout<<"                                                                  " <<std::endl;
        std::cout<<"==================================================================" <<std::endl;
    }

    file.close();
}



// end of the program

//-------------------------------------------------------------------------------------------------
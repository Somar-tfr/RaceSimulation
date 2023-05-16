#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section
struct Race{
  int numberOfLaps;
  int currentLap;
  char* firstPlaceDriverName;
  char* firstPlaceRaceCarColor;

};

struct RaceCar{
  char* driverName;
  char* raceCarColor;
  int totalLapTime;
};

// Print functions section
void printIntro(void);
void printCountDown(void);
void printFirstPlaceAfterLap(struct Race race);
void printCongratulation(struct Race race);


// Logic functions section
int calculateTimeToCompleteLap(void);
void updateRaceCar(struct RaceCar* raceCar);
void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2);
void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2);

int main() {
	srand(time(0));
  printIntro();
  printCountDown();

  struct RaceCar r1 = {"me", "red", 0};
  struct RaceCar r2 = {"you", "blue", 0};
  startRace(&r1, &r2);

};

void printIntro(void)
{
  printf("Welcome to out main event digital race fans!\n I hope everybody has their snaks because we\n are about  to begin!\n");
}

void printCountDown(void)
{
  printf("Racers Ready! In...\n5\n4\n3\n2\n1\nRace!\n");
}

void printFirstPlaceAfterLap(struct Race race){
  printf("After lap number%d\nFirst Place Is: %s in the %s race car!\n", race.currentLap, race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race)
{
  printf("Let's all congratulate Cosmo in the %s race car for an amazing performance. It truly was a great race and everybody have a goodnight!", race.firstPlaceRaceCarColor);
}
int calculateTimeToCompleteLap(void)
{

  int speed = rand() % 3 + 1;
  int acceleration = rand() % 3 + 1;
  int nerves = rand() % 3 + 1;
  return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar* raceCar)
{
  raceCar -> totalLapTime += calculateTimeToCompleteLap();
}
void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2)
{
  if (raceCar1->totalLapTime <= raceCar2->totalLapTime)
  {
    race -> firstPlaceDriverName = raceCar1->driverName;
    race -> firstPlaceRaceCarColor = raceCar1->raceCarColor;

  }
  else
  {
    race -> firstPlaceDriverName = raceCar2->driverName;
    race -> firstPlaceRaceCarColor = raceCar2->raceCarColor;
  }
}

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2)
{
  struct Race race ={5,1, " ", " "};
  for(int i = 0; i < race.numberOfLaps; i++)
  {
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);


  }
  printCongratulation(race);

}

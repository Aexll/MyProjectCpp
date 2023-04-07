// Fill out your copyright notice in the Description page of Project Settings.


#include "CppMazeGenerator.h"


ACppMazeGenerator::ACppMazeGenerator()
{
    PrimaryActorTick.bCanEverTick = false;

    MeshComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Mesh Component"));
    RootComponent = MeshComponent;
}

/// <summary>
/// Will generate TArray of size SizeOfPlan² with random value (0 or 1);
/// </summary>
/// <param name="SizeOfPlan"></param>
/// <returns></returns>
TArray<int32> ACppMazeGenerator::Generate2DArray(int32 SizeOfPlan)
{
    TArray<int32> MyArray;
    MyArray.Init(0, SizeOfPlan * SizeOfPlan);

    for (int i = 0; i < MyArray.Num(); i++)
    {
        MyArray[i] = GetRandomValue();
    }

    return MyArray;
    //return TArray<int32>();
}

int32 ACppMazeGenerator::GetRandomValue()
{
    return FMath::RandBool() ? 1 : 0;
}

/// <summary>
/// Will place block instances in the map at the right position based on MyArray
/// </summary>
void ACppMazeGenerator::PopulatePlan()
{
    UStaticMesh* CubeMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube"));

    FVector LocationOffset = FVector(-SizeOfPlan * 200.f / 2.f, -SizeOfPlan * 200.f / 2.f, 0.f);

    for (int32 RowIndex = 0; RowIndex < SizeOfPlan; RowIndex++)
    {
        for (int32 ColIndex = 0; ColIndex < SizeOfPlan; ColIndex++)
        {
            if (MyArray[RowIndex * SizeOfPlan + ColIndex] == 1)
            {
                FTransform InstanceTransform = FTransform(LocationOffset + FVector(RowIndex * 200.f, ColIndex * 200.f, 0.f));
                MeshComponent->AddInstance(InstanceTransform);
            }
        }
    }
}

/// <summary>
/// Will generate a "maze" of zero and return it, give the size of one side in paramater
/// </summary>
/// <param name="MazeSize"></param>
/// <returns></returns>
TArray<int32> ACppMazeGenerator::GenerateMaze(int32 MazeSize)
{
    TArray<int32> Maze;
    Maze.Init(1, MazeSize * MazeSize);

    int32 StartRow = 1;
    int32 StartCol = 1;

    Maze[StartRow * MazeSize + StartCol] = 0;
    GenerateMazeRecursive(Maze, MazeSize, StartRow, StartCol);

    return Maze;
}

/// <summary>
/// Simple recursive function that will trace the path of the maze
/// </summary>
/// <param name="Maze"></param>
/// <param name="MazeSize"></param>
/// <param name="Row"></param>
/// <param name="Col"></param>
void ACppMazeGenerator::GenerateMazeRecursive(TArray<int32>& Maze, int32 MazeSize, int32 Row, int32 Col)
{
    TArray<int32> Directions = { 0, 1, 2, 3 };
    //FMath::ArrayShuffle(Directions);


    // Shuffle the Directions array
    for (int32 Index = 0; Index < Directions.Num() - 1; Index++)
    {
        int32 RandomIndex = FMath::RandRange(Index, Directions.Num() - 1);
        Directions.Swap(Index, RandomIndex);
    }



    for (int32 Index = 0; Index < 4; Index++)
    {
        int32 Dir = Directions[Index];

        int32 NextRow = Row;
        int32 NextCol = Col;

        if (Dir == 0 && Row > 0)
        {
            NextRow--;
        }
        else if (Dir == 1 && Row < MazeSize - 1)
        {
            NextRow++;
        }
        else if (Dir == 2 && Col > 0)
        {
            NextCol--;
        }
        else if (Dir == 3 && Col < MazeSize - 1)
        {
            NextCol++;
        }

        if (Maze[NextRow * MazeSize + NextCol] == 1)
        {
            Maze[NextRow * MazeSize + NextCol] = 0;
            Maze[((NextRow + Row) / 2) * MazeSize + ((NextCol + Col) / 2)] = 0;
            GenerateMazeRecursive(Maze, MazeSize, NextRow, NextCol);
        }
    }
}

TArray<int32> ACppMazeGenerator::GenerateMaze_2(int32 mazesize)
{
    TArray<int32> Maze;

    // Initialize maze with all walls
    for (int32 i = 0; i < mazesize * mazesize; i++)
    {
        Maze.Add(1);
    }

    // Create entrance and exit
    Maze[0] = 0;  // Entrance
    Maze[mazesize * mazesize - 1] = 0;  // Exit

    // Create random paths
    int32 CurrentPosition = 0;  // Start at entrance
    TArray<int32> VisitedCells;
    VisitedCells.Add(CurrentPosition);

    while (VisitedCells.Num() > 0)
    {
        // Get neighbors of current position
        TArray<int32> Neighbors;
        int32 x = CurrentPosition % mazesize;
        int32 y = CurrentPosition / mazesize;

        if (x > 0)  // Left neighbor
        {
            int32 NeighborPosition = CurrentPosition - 1;
            if (Maze[NeighborPosition] == 1)
            {
                Neighbors.Add(NeighborPosition);
            }
        }
        if (x < mazesize - 1)  // Right neighbor
        {
            int32 NeighborPosition = CurrentPosition + 1;
            if (Maze[NeighborPosition] == 1)
            {
                Neighbors.Add(NeighborPosition);
            }
        }
        if (y > 0)  // Top neighbor
        {
            int32 NeighborPosition = CurrentPosition - mazesize;
            if (Maze[NeighborPosition] == 1)
            {
                Neighbors.Add(NeighborPosition);
            }
        }
        if (y < mazesize - 1)  // Bottom neighbor
        {
            int32 NeighborPosition = CurrentPosition + mazesize;
            if (Maze[NeighborPosition] == 1)
            {
                Neighbors.Add(NeighborPosition);
            }
        }

        // Choose a random neighbor to move to
        if (Neighbors.Num() > 0)
        {
            int32 RandomIndex = FMath::RandRange(0, Neighbors.Num() - 1);
            int32 NewPosition = Neighbors[RandomIndex];

            // Create path between current position and new position
            if (NewPosition == CurrentPosition - 1)  // Left neighbor
            {
                Maze[CurrentPosition - 1] = 0;
            }
            else if (NewPosition == CurrentPosition + 1)  // Right neighbor
            {
                Maze[CurrentPosition + 1] = 0;
            }
            else if (NewPosition == CurrentPosition - mazesize)  // Top neighbor
            {
                Maze[CurrentPosition - mazesize] = 0;
            }
            else if (NewPosition == CurrentPosition + mazesize)  // Bottom neighbor
            {
                Maze[CurrentPosition + mazesize] = 0;
            }

            // Move to new position
            CurrentPosition = NewPosition;
            VisitedCells.Add(CurrentPosition);
        }
        else
        {
            // Backtrack to last visited cell
            VisitedCells.RemoveAt(VisitedCells.Num() - 1);
            CurrentPosition = VisitedCells.Num() > 0 ? VisitedCells.Last() : CurrentPosition;
        }
    }

    return Maze;
}

// Called when the game starts or when spawned
void ACppMazeGenerator::BeginPlay()
{
	Super::BeginPlay();

    //MyArray = ACppMazeGenerator::Generate2DArray(SizeOfPlan);
    MyArray = GenerateMaze_2(SizeOfPlan);

    PopulatePlan();

}

// Called every frame
void ACppMazeGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


# CS225 Final Project
## Akshay Bhamidipati, Franklin Moy, Vish Gopal Sekar
- Building/Compiling this project:
  - Download or clone this repository.
  - Compile this project by running make in your terminal:
    - Navigate to the directory containing this project and type "make" in your terminal.
- Running this project:
  - Type `./finalproj` to run the executable with no arguments.
    - This will run a DFS traversal with a source airport of AAE, a Prim's Minimum Spanning Tree starting from airport AER, and a landmark path traversal starting from ORD to CMI with a stop in JFK.
  - Each algorithm will write its results to a file. (The program will tell you the file names in the terminal.)
    - For the outputs for DFS and Landmark Path, the traversal is to be read from top to bottom.
    - The output for Prim's lists all of the edges in the generated MST in alphabetical order with respect to the second column.
      - Format: Source - Sink   Weight
  - You can also run each individual algorithm independently by typing the name of the algorithm after the executable:
    - DFS: `./finalproj dfs [sourceAirport]`
      - Note that airport codes are in ALL CAPS. An undefined output will occur if you use any lowercase characters.
      - If you only enter `./finalproj dfs`, the program will run a DFS from every single airport.
    - Prims: `./finalproj prims`
      - The program will not run if you add more arguments on top of "prims". 
      - If there exist discontinuities in the dataset, the output file will not include them.
    - Landmark Path: `./finalproj landmark [sourceAirport][landmarkAirport][destinationAirport]`
      - Note that airport codes are in ALL CAPS. An undefined output will occur if you use any lowercase characters. 
      - landmarkAirport is the airport that the traversal will visit on its way from sourceAirport to destinationAirport.
      - If you only enter `./finalproj landmark`, the program will run a landmark path traversal starting from ORD to CMI with a stop in JFK.
- Dataset:
  - See [dataset_README.md](dataset/dataset_README.md) for more information on the OpenFlights dataset used.  
- Our observations and results:
  - See [RESULTS.md](RESULTS.md).
  - Watch our video presentation [here](https://drive.google.com/file/d/1b-3CGkXxFuGSoN2V78OcTwV1PZ_tbpMv/view?usp=sharing).
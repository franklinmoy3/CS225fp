# Interesting observations about the dataset

* By running our Prim's MST algorithm on the OpenFlights dataset, we were able to see discontinuities in the graph by seeing which edges connected to nothing. We then ran these airports into our DFS to find the other airports in each cluster of discontinuities. There are 26 airports in total that are disconnected. These involve the following locations:
  * The islands of New Caledonia: NOU airport only handles international flights and doesn't have flights to the domestic airports of New Caledonia.
    * Run a DFS on airport TOU to see all of 10 these airports. 
  * Alaska, U.S.A.: A cluster of small airports in the state of Alaska do not have flights that go to other states.
    * These airports are AKB, DUT, IKO, and KQA.
  * Washington, U.S.A.: A cluster of small airports in the state of Washington do not have flights that go to other states.
    * These airports are BFI, CLM, ESD, FRD
  * Greenland: Airports CNP and OBY are domestic airports that only travel between each other.
  * British Columbia, Canada: CXH and YWH airports are actually sea ports that only have flights between each other according to the dataset.
  * Namibia: A cluster of airports in Namibia only travel between each other.
    * These airports are ERS, MPA, NDU, OND
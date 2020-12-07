# OpenFlights dataset

airports.dat and routes.dat were provided by OpenFlights (https://openflights.org/data.html). routes_simplified.dat was created by trimming unneeded data from routes.dat, such as airline, equipment, and codeshare information, and removing duplicate routes after the aforementioned data was trimmed.  
* routes_simplified.csv is a CSV file with formatting as follows:
  * SourceAirport,DestinationAirport,numberOfStopsAlongRoute
* routes_simplified is guaranteed to contain only unique routes
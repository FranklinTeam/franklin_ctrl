%map = load("map.mat");
imread('map.pgm')

%Cant Read the map ...from ROS msg... sh!t
imageNorm = double(ans)/255;
imageOccupancy = 1 - imageNorm;
mapi = occupancyMap(imageOccupancy,20);

%Ajust the size to the robot diameter
mapInflated = copy(mapi);
robotRadius = 0.1;
inflate(mapInflated,robotRadius);

%Create a probalistic road map
prm = mobileRobotPRM;
prm.Map = mapInflated;
prm.NumNodes = 50;
prm.ConnectionDistance = 5;


show(mapi)
show(mapInflated)
show(prm)

save("map.mat")

%Find a path (path being probabilistic)
waypoints = findpath(prm, [0,0], [1,1])

#include <ros/ros.h>
// CPP code for printing shortest path between
// two vertices of unweighted graph
#include <bits/stdc++.h>
#include <franklin/CmdRobot.h>
#include <franklin/PackageRobot.h>
using namespace std;

// utility function to form edge between two vertices
// source and dest
void add_edge(vector<int> adj[], int src, int dest, std::string name, vector<int> to, vector<int> from, vector<std::string> voisin_name)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
    from.push_back(src);
    to.push_back(dest);
    voisin_name.push_back(name);
}

// a modified version of BFS that stores predecessor
// of each vertex in array p
// and its distance from source in array d
bool BFS(vector<int> adj[], int src, int dest, int v,
         int pred[], int dist[]){
    // a queue to maintain queue of vertices whose
    // adjacency list is to be scanned as per normal
    // DFS algorithm
    list<int> queue;
    // boolean array visited[] which stores the
    // information whether ith vertex is reached
    // at least once in the Breadth first search
    bool visited[v];
    // initially all vertices are unvisited
    // so v[i] for all i is false
    // and as no path is yet constructed
    // dist[i] for all i set to infinity
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
    // now source is first to be visited and
    // distance from source to itself should be 0
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);
    // standard BFS algorithm
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);

                // We stop BFS when we find
                // destination.
                if (adj[u][i] == dest)
                    return true;
            }
        }
    }
    return false;
}

// utility function to print the shortest distance
// between source vertex and destination vertex
vector<int> printShortestDistance(vector<int> adj[], int s, int dest, int v){
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from s
    int pred[v], dist[v];
    vector<int> path;

    if (BFS(adj, s, dest, v, pred, dist) == false) {
        cout << "Given source and destination"
             << " are not connected";
             path.push_back(0);
        return path;
    }
    // vector path stores the shortest path

    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    return path;
}

std::string nodeFromName;
std::string nodeToName;
bool sendAction = false;

void com_tb1_Callback(const franklin::PackageRobot msg){
  if(msg.package && nodeToName.compare("tb1") == 0){
    sendAction = true;
  }
}

void com_tb2_Callback(const franklin::PackageRobot msg){
  if(msg.package && nodeToName.compare("tb2") == 0){
    sendAction = true;
  }
}

void com_tb3_Callback(const franklin::PackageRobot msg){
  if(msg.package && nodeToName.compare("tb3") == 0){
    sendAction = true;
  }
}

void com_tb4_Callback(const franklin::PackageRobot msg){
  if(msg.package && nodeToName.compare("tb4") == 0){
    sendAction = true;
  }
}

int main(int argc, char* argv[])
{
  ros::init(argc, argv, "scheduler");

  // no. of vertices
    int v = 4;
    int nodeEND = 3;
    int nodeBEGIN = 0;

    // array of vectors is used to store the graph
    // in the form of an adjacency list
    vector<int> adj[v];
    vector<int> path;

    vector<int> to;
    vector<int> from;
    vector<std::string> voisin_name;
    int counterAction = 0;



    // Creating graph given in the above diagram.
    // add_edge function takes adjacency list, source
    // and destination vertex as argument and forms
    // an edge between them.
    add_edge(adj, 0, 1, "tb1", to, from, voisin_name);
    add_edge(adj, 0, 2, "tb3", to, from, voisin_name);
    add_edge(adj, 1, 0, "tb1", to, from, voisin_name);
    add_edge(adj, 1, 3, "tb4", to, from, voisin_name);
    add_edge(adj, 2, 0, "tb1", to, from, voisin_name);
    add_edge(adj, 2, 3, "tb4", to, from, voisin_name);
    add_edge(adj, 3, 2, "tb3", to, from, voisin_name);
    add_edge(adj, 3, 1, "tb2", to, from, voisin_name);

    path = printShortestDistance(adj, nodeBEGIN, nodeEND, v);
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " \n";

  ros::NodeHandle nh;
  ros::Subscriber sub_from_tb1 = nh.subscribe("/COM_tb1_to_ctrl", 1, com_tb1_Callback);
  ros::Subscriber sub_from_tb2 = nh.subscribe("/COM_tb2_to_ctrl", 1, com_tb2_Callback);
  ros::Subscriber sub_from_tb3 = nh.subscribe("/COM_tb3_to_ctrl", 1, com_tb3_Callback);
  ros::Subscriber sub_from_tb4 = nh.subscribe("/COM_tb4_to_ctrl", 1, com_tb4_Callback);
  ros::Publisher pub_to_tb1 = nh.advertise<franklin::CmdRobot>("/COM_ctrl_to_tb1", 1);
  ros::Publisher pub_to_tb2 = nh.advertise<franklin::CmdRobot>("/COM_ctrl_to_tb2", 1);
  ros::Publisher pub_to_tb3 = nh.advertise<franklin::CmdRobot>("/COM_ctrl_to_tb3", 1);
  ros::Publisher pub_to_tb4 = nh.advertise<franklin::CmdRobot>("/COM_ctrl_to_tb4", 1);

  ros::Rate loop_rate(10);

  sendAction = true;
  counterAction = path.size()-1;

  while (ros::ok()){
     ros::spinOnce();

     if(sendAction){
       int nodeFrom = path[counterAction];
       counterAction--;
       int nodeTo = path[counterAction];
       nodeFrom++;
       nodeTo++;

       for(std::size_t i = 0; i < to.size(); ++i){

         if(to[i]+1 == nodeTo && from[i]+1 == nodeFrom){
           nodeToName = voisin_name[i];
           ROS_INFO("-- RIGHT FOR to : %d, from : %d", to[i]+1, from[i]+1);
         }else{
           ROS_INFO("WRONG FOR to : %d, from : %d", to[i]+1, from[i]+1);
         }
       }

       nodeFromName = "tb"+nodeFrom;

       ROS_INFO("Yeah F : %d", nodeFrom);
       ROS_INFO("Yeah T : %d", nodeTo);
       std::cout << nodeToName << " lol \n";

       franklin::CmdRobot msg;
       msg.obj_x = 0;
       msg.obj_y = 0;
       msg.robot_name = nodeToName;
       msg.from_robot = (nodeTo == nodeEND);
       msg.reception = false;

       if(nodeToName.compare("tb1") == 0){
         pub_to_tb1.publish(msg);
       }else if(nodeToName.compare("tb2") == 0){
         pub_to_tb2.publish(msg);
       }else if(nodeToName.compare("tb3") == 0){
         pub_to_tb3.publish(msg);
       }else if(nodeToName.compare("tb4") == 0){
         pub_to_tb4.publish(msg);
       }

       msg.obj_x = 0;
       msg.obj_y = 0;
       msg.robot_name = nodeFromName;
       msg.from_robot = (nodeFrom == nodeBEGIN);
       msg.reception = true;

       if(nodeFromName.compare("tb1") == 0){
         pub_to_tb1.publish(msg);
       }else if(nodeFromName.compare("tb2") == 0){
         pub_to_tb2.publish(msg);
       }else if(nodeFromName.compare("tb3") == 0){
         pub_to_tb3.publish(msg);
       }else if(nodeFromName.compare("tb4") == 0){
         pub_to_tb4.publish(msg);
       }

       sendAction = false;
     }

     loop_rate.sleep();
  }
}

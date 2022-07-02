#include <cstdio>
#include <cstdlib>
#include <climits>
#include <unordered_map>
#include <ctime>
#include <cmath>
#include <vector>
#include <string>
#include <numeric>

//integer type
#define lli long long int
#define vectorlli std::vector<lli>

//distance walked in one step
#define step 10

//food locations
class Food
{
    private:
        //generate key for hash table
        std::string key(lli x,lli y) {return std::to_string(x) + "," + std::to_string(y);}

    public:
        //store locations (coordinates of points (x,y)) in hash table
        //key is the string "x,y"
        //value is the vector (x,y)
        std::unordered_map<std::string,vectorlli> points;
        //store locations (coefficients of lines a*x+b*y+c>=0) in list of vectors
        lli number_of_lines;
        vectorlli *lines;
        //store locations (coefficients of ellipses a*x^2+b*x+c*y^2+d*y+e>0) in list of vectors
        lli number_of_ellipses;
        vectorlli *ellipses;

        //read locations from files
        //game tells which files
        Food(int game);
        //free memory
        ~Food()
        {
            if(number_of_lines)
                free(lines);
            if(number_of_ellipses)
                free(ellipses);
        }
        //copy constructor
        Food(const Food &other)
        {
            points=other.points;
            number_of_lines=other.number_of_lines;
            if(number_of_lines)
            {
                lines=(vectorlli *)malloc(sizeof(vectorlli)*number_of_lines);
                for(lli i=0;i<number_of_lines;i++)
                {
                    lines[i]=other.lines[i];
                }
            }
            
            number_of_ellipses=other.number_of_ellipses;
            if(number_of_ellipses)
            {
                ellipses=(vectorlli *)malloc(sizeof(vectorlli)*number_of_ellipses);
                for(lli i=0;i<number_of_ellipses;i++)
                    ellipses[i]=other.ellipses[i];
            }
        }
        //assignement operator
        Food& operator=(const Food& other)
        {
            if(this!=&other)
            {
                points=other.points;
                if(number_of_lines)
                {
                    free(lines);
                    number_of_lines=other.number_of_lines;
                    lines=(vectorlli *)malloc(sizeof(vectorlli)*number_of_lines);
                    for(lli i=0;i<number_of_lines;i++)
                    {
                        lines[i].clear();
                        lines[i]=other.lines[i];
                    }
                }
                if(number_of_ellipses)
                {
                    free(ellipses);
                    number_of_ellipses=other.number_of_ellipses;
                    ellipses=(vectorlli *)malloc(sizeof(vectorlli)*number_of_ellipses);
                    for(lli i=0;i<number_of_ellipses;i++)
                    {
                        ellipses[i].clear();
                        ellipses[i]=other.ellipses[i];
                    }
                }
            }
            return *this;
        }

        //we share key with ant
        friend class Ant;
};

Food::Food(int game)
{
    FILE *file;
    switch(game)
    {
        case 1:
            file=fopen("food_points_1.txt","r");
            break;
        case 2:
            file=fopen("food_points_2.txt","r");
            break;
        case 3:
            file=fopen("food_points_3.txt","r");
            break;
    }
    std::string tmp;
    lli x,y;
    while(fscanf(file,"%lld %lld\n",&x,&y)==2)
    {
        tmp=key(x,y);
        points[tmp].push_back(x);
        points[tmp].push_back(y);
    }
    fclose(file);

    switch(game)
    {
        case 1:
            file=fopen("food_lines_1.txt","r");
            break;
        case 2:
            file=fopen("food_lines_2.txt","r");
            break;
        case 3:
            file=fopen("food_lines_3.txt","r");
            break;
    }
    lli a,b,c;
    number_of_lines=0;
    lines=NULL;
    while(fscanf(file,"%lld %lld %lld\n",&a,&b,&c)==3)
    {
        number_of_lines++;
        lines=(vectorlli *)realloc(lines,sizeof(vectorlli)*number_of_lines);
        lines[number_of_lines-1].push_back(a);
        lines[number_of_lines-1].push_back(b);
        lines[number_of_lines-1].push_back(c);
    }
    fclose(file);

    switch(game)
    {
        case 1:
            file=fopen("food_ellipses_1.txt","r");
            break;
        case 2:
            file=fopen("food_ellipses_2.txt","r");
            break;
        case 3:
            file=fopen("food_ellipses_3.txt","r");
            break;
    }
    lli d,e;
    number_of_ellipses=0;
    ellipses=NULL;
    while(fscanf(file,"%lld %lld %lld %lld %lld\n",&a,&b,&c,&d,&e)==5)
    {
        number_of_ellipses++;
        ellipses=(vectorlli *)realloc(ellipses,sizeof(vectorlli)*number_of_ellipses);
        ellipses[number_of_ellipses-1].push_back(a);
        ellipses[number_of_ellipses-1].push_back(b);
        ellipses[number_of_ellipses-1].push_back(c);
        ellipses[number_of_ellipses-1].push_back(d);
        ellipses[number_of_ellipses-1].push_back(e);
    }
    fclose(file);
}

// ant
class Ant
{
    public:
        //position (x,y)
        vectorlli position;

        //ant begins at position=(0,0) at t=0
        //ant walks 1 step in any direction up/down/left/right per time unit
        //ant stops upon reaching any food
        //repeat this walk and return average time
        vectorlli search_for_food(const Food &food, lli number_walks);

        //create ant
        Ant() {srand(time(NULL));}
        //no need of custom destructor, copy nor assignement operators
};

vectorlli Ant::search_for_food(const Food &food, lli number_walks)
{
    //local copy
    Food food_copy=food;

    //store finish times of each walk
    //initialise to 0
    vectorlli times(number_walks,0);

    for(lli index_walk=0;index_walk<number_walks;++index_walk)
    {
        //place ant in (0,0)
        position.clear();
        position.push_back(0);
        position.push_back(0);

        bool flag=false;

        while(true)
        {
            //check ant is on food
            if(food_copy.points.find(food_copy.key(position[0],position[1]))!=(food_copy.points.end()))
                break;

            for(lli i=0;i<food.number_of_lines;++i)
            {
                if(((food_copy.lines[i])[0])*position[0]+((food_copy.lines[i])[1])*position[1]+((food_copy.lines[i])[2])>=0)
                {
                    flag=true;
                    break;
                }
            }

            if(flag)
                break;

            for(lli i=0;i<food.number_of_ellipses;++i)
            {
                if(((food_copy.ellipses[i])[0])*position[0]*position[0]+((food_copy.ellipses[i])[1])*position[0]+((food_copy.ellipses[i])[2])*position[1]*position[1]+((food_copy.ellipses[i])[3])*position[1]+((food_copy.ellipses[i])[4])>0)
                {
                    flag=true;
                    break;
                }
            }

            if(flag)
                break;

            //ant makes a step in a random direction
            switch(rand()%4)
            {
                case 0:
                    position[0]+=step;
                    break;
                case 1:
                    position[0]-=step;
                    break;
                case 2:
                    position[1]+=step;
                    break;
                case 3:
                    position[1]-=step;
                    break;
            }
            times[index_walk]++;
        }
    }

    return times;
}

int main(int argc, char *argv[])
{
    lli number_walks=atoll(argv[2]);

    Ant ant;
    Food food(atoi(argv[1]));
    vectorlli times=ant.search_for_food(food,number_walks);
    
    //print
    double mean = (double) std::accumulate(times.begin(), times.end(),0);
    mean = mean / ((double) number_walks);

    std::vector<double> diff(number_walks);
    for(lli i=0;i<number_walks;i++)
    {
        diff[i]=((double) times[i])-mean;
    }
    double std_dev=std::inner_product(diff.begin(),diff.end(),diff.begin(),0.0);
    std_dev = sqrt(std_dev/((double) number_walks));

    printf("\nAverage time = %lf ± %lf\n\n",mean,std_dev);
}
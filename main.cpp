#include "MarkerManager.hpp"
#include <iostream>

int main()
{
    MarkerManager manager;

    int choice;
    int threshold;

    Marker m1={1,100,200,80};
    Marker m2={2,200,-50,95};
    Marker m3={3,0,0,60};

    std::cout<<"tianjiabianhao1:"
             <<(manager.add(m1)?"chenggong":"shibai")<<'\n';
    std::cout<<"tianjiabianhao2:"
             <<(manager.add(m2)?"chenggong":"shibai")<<'\n';
    std::cout<<"tianjiabianhao3:"
             <<(manager.add(m3)?"chenggong":"shibai")<<'\n';
    
    Marker duplicate={2,300,400,70};

    std::cout<<"chongfutianjiabianhao2:"
             <<(manager.add(duplicate)?"chenggong":"shibai")<<'\n';
    
    Marker invalid={4,100,100,101};

    std::cout<<"tianjiayouxianji101dejilu:"
             <<(manager.add(invalid)? "chenggong":"shibai")<<'\n';

    std::cout<<"\nquanbubiaojijilu:\n";
    manager.displayAll();

    std::cout<<"\nbainhao2shifocunzai"
             <<(manager.contains(2) ? "chenggong":"shibai")<<'\n';

    std::cout<<"\nbainhao10shifocunzai"
             <<(manager.contains(10) ? "chenggong":"shibai")<<'\n';

    std::cout<<"\nypuxianjibudiyu80dejilushu:"
             <<manager.countByPriority(80)<<'\n';
    
    std::cout<<"\nypuxianjibudiyu90dejilushu:"
             <<manager.countByPriority(90)<<'\n';

    MarkerManager emptyManager;
    std::cout<<"\nkongguanliqidejilushu(fazhi80):"
             <<emptyManager.countByPriority(80)<<'\n';
    
    Marker marker1{};

    MarkerManager manager1;

    manager1.add(marker1);

    while(choice!=0)
    {
        std::cout<<"----- flag manager menu -----\n"
             <<"1.watch whole flag\n"
             <<"2.add flag\n"
             <<"3.acquire number\n"
             <<"4.calculate by priority\n"
             <<"0.leave off\n"
             <<"choose your operation\n";
        std::cin>>choice;

        switch(choice)
        {
            case 1 :
            {
                manager1.displayAll();
                break;
            }

            case 2 :
            {
                std::cout<<"id\n";
                std::cin >> marker1.id;
                std::cout<<"x_mm\n";
                std::cin >> marker1.x_mm;
                std::cout<<"y_mm\n";
                std::cin >> marker1.y_mm;
                std::cout<<"priority(0-100)\n";
                std::cin >> marker1.priority;
                if (manager1.add(marker1))
                  {
                    std::cout<<"the flag is alive\n";
                  }
                else
                  {
                    std::cout<<"the flag is died\n";
                  }
                break;
            }

            case 3 :
            {
                int id;
                std::cout<<"enter marker ID\n";
                std::cin>>id;
                if(manager1.contains(id))
                 {
                    std::cout<<"Marker exists.\n";
                 }
                else
                 {
                    std::cout<<"Marker does not exists.\n";
                 }
                break;
            }


            case 4 :
            {
                std::cout<<"enter priority threshold:\n";
            std::cin >> threshold;
            std::cout<<manager1.countByPriority(threshold)
                     <<'\n';
            break;
            }

            case 0 :
            {
                std::cout<<"the program is over\n";
            break;
            }

            default:
            {
                std::cout<<"the flag is error\n";
            break;
            }       

        }
    }
        
    return 0;

}
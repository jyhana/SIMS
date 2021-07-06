<!--
 * @Description: 
 * @Version: 2.0
 * @Autor: JYHan
 * @Date: 2021-07-06 15:54:36
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-07-06 21:46:14
-->
# ISMS系统操作手册
## 一、 功能需求
1. 学生信息录入</br>
2. 学生信息修改</br>
3. 学生信息删除</br>
4. 全部信息显示</br>
5. 根据学号查找学生信息</br>
6. 保存信息到文件</br>
7. 从文件导入信息</br>
## 二、 注意事项
### 2.1设计原则
1. 第一个版本我主要写的是控制台应用程序。
2. 把学生信息（学号、姓名、成绩）保存到txt文件中T。
3. 为了让用户和软件之间可以交互，设计了一个处理界面的类MainView。
### 2.2 类的设计
1. main():主函数
2. Student(实体对象类)，添加成员属性：学号id，姓名name，成绩score。
3. SFn(处理信息类)，是一个用来提供业务功能的类。比如说添加一个学生，删除一个学生…。这个类是实现业务功能的类，执行业务功能，把执行结果交给view层。
4. MainView（处理界面更新功能类），相当于界面层（视图层，View层）。不仅是更新界面，还有处理用户的输入，调用下面SFn类中对应的函数实现对应功能。
### 2.3 数据存储
1. 在软件执行过程中，数据存在内存中。为了在内存中保存学生，用了一个map<int, CStu> 的stu_map。用学号id作为map的key，用stu作为map的value。选择map，主要是为了避免学号重复。
2. 需要保存学生信息至硬盘时，数据写入硬盘上的TXT中。保存方式是：一行对应一个学生。每一行都有三列，分别是id，name和score。这三个“字段”分别对应stu的三个成员属性。同时，各个字段之间，用一个空格隔开。为了方便地把map中的所有学生信息全部写入到文件中，我重载了stu的<<运算符，实现把一个stu对象的3个成员变量的值，<<到输出流ostream中。写文件的时候，调用stringstream、<<stu，再把stringstream的str()字符串内容<<到ofstream（文件的输出流）中。
3. 为了从文件读入学生信息，采用一行一行读取的方式。通过重载stu的>>运算符，实现把字符串直接载入一个stu对象的功能。
## 三、 代码排版
&emsp;&emsp;本项目我采用cmake编译代码，所以编写了CMakelists.txt文件来执行代码编译。
具体是：</br>

|-SIMS  
&emsp;|-build  
&emsp;&emsp;|-  
&emsp;|-include  
&emsp;&emsp;|-Student.h  
&emsp;&emsp;|-SFn.h  
&emsp;&emsp;|-MainView.h    
&ensp;|-src  
&emsp;&emsp;|-Student.cpp  
&emsp;&emsp;|-SFn.cpp  
&emsp;&emsp;|-MainView.cpp  
&emsp;&emsp;|-main.cpp

## 四、 开发流程  
&emsp;&emsp;本项目虽然比较简单，当时尽管项目再小，都要养成良好的习惯：先搭建框架，再往里面填内容。
如果不这样做，后果就是，要崩溃的。
### 4.1 搭建框架  
1. 实体类Student  
   首先定义两个友元函数用来访问private成员；同时重载>>和<<运算符用来读取/导入txt文件；  
    ```c++
    /* friend function */ 
    friend std::ostream & operator<<(std::ostream & os, CStudent & stu);  
    friend std::istream & operator>>(std::istream & is, CStudent & stu);
    ```
    定义成员函数(public)和成员变量(private)：   
    1）函数： 
    ```c++  
    int getId() const;  
    void setId(int val);  
    std::string getName() const;  
    void setName(std::string val);
    double getScore() const;
    void setScore(double val);
    ```  
    2）变量  
    ```c++
    int id;  
    std::string name;  
    double score
    ```
    Student.cpp中具体实现这些函数
    ```c++ 
    std::ostream & operator<<(std::ostream & os, Student & stu)  {  
        os<<stu.getId()<<"     "<<stu.getName()<<"     "<<stu.getAge();  
        return os;} 
    std::istream & operator>>(std::istream & is, Student & stu) {  
        is>>stu.id>>stu.name>>stu.age;
        return is;}
    ```
    ``` c++  
    #include "Student.h" 
    // 学生默认id是-1，说明这暂时是一个无效的学生。
    Student::Student(){this->id = -1;}
    Student::~Student(){}
    int Student::getId() const { return id; }
    void Student:: setId(int val) { id = val; }
    std::string Student:: getName() const { return name; }
    void Student:: setName(std::string val) { name = val; }
    int Student:: getScore() const { return score; }
    void Student:: setScore(double val) { age = val; }
    ```
2. 业务功能类SFn  
    &emsp;&emsp;这里为了开发业务类，为了让软件的功能不重不漏，我就对照着最开始的需求里的功能列表来写的。
     ``` c++   
    Student addStu(std::map<int,Student> & m1,Student & stu);// 增添
    bool deleteStuById(std::map<int, Student> & m1,const int & id);// 删除
    Student updateStu(std::map<int, Student> & m1, const Student & stu);// 修改
    Student findById(const std::map<int, Student> & m1, const int & id) const; // 查询
    void showAll(const std::map<int, Student> & m1 ) const;// 显示所有
    bool saveToFile(const std::map <int,Student> & m1,const std::string & pathName) const;//保存文件
    bool readFromFile(std::map<int, Student> & m1, std::string path);//导入文件 
    ```
    &emsp;&emsp;这样一来，主要最后需要实现哪些功能呢。可以在定义函数的时候多写注释！增加可读性。e.g. 输入变量是什么，返回值是什么，什么样的情况下返回什么样的结果……开发完head文件以后，再到它对应的CPP文件中，完成函数体。e.g. 如果要求返回int，在{   }里直接写个return 0; 就好。总而言之，先搭框架，再去写功能函数. 
    ```C++
    #include "SFn.h"
    Student SFn:: addStu(map<int,Student> & m1,Student & stu) {return stu;}// 增  
    bool  SFn:: deleteStuById(map<int, Student> & m1, const int & id) {bool b = false;return b;}// 删  
    Student SFn:: updateStu(map<int,Student> & m1,const Student & stu) {Student stu;return stu;}// 改
    Student  SFn:: findById(const map <int, Student> & m1, const int & id) const{Student stu ;return stu;}// 查 by id  
    void  SFn:: showAll(const map<int,Student> & m1) const{}// showAll
    bool SFn::saveToFile(const map <int,Student> & m1,const string & pathName) const{bool b = true;   return b;}// save to file
    bool SFn:: readFromFile(std::map<int,Student> & m1, std::string path) {bool b = true;return b;}  // read from file
    ```
3. 视图交互类MainView  
   这一部分我们主要写交互界面，可以对着功能清单来写。
   ```c++
   /* 欢迎 */
    void welcome();
    /* 显示菜单 */
    void showMenu();
    /* view 显示所有学生 */
    void showAllStuAtView(const std::map<int, Student> & stu_m1);
    /* view层 添加一个学生 */
    void addStuAtView( std::map<int, Student> & stu_m1 );
    /* view 查找一个学生 */
    void findStuAtView(const std::map<int, Student> & m1) ;
    /* view层删除一个学生 */
    void deleteByIdAtView(std::map<int, Student> & v1);
    /* view层 更新一个学生 */
    void updateByIdAtView(std::map<int, Student> & m1);
    /* view层 把map保存进文件 */
    void saveToFileAtView(const std::map<int, Student> & m1, std::string pathName);
    /* view层 把文件中的东西导入 map */
    void readFromFileAtView(std::map<int, Student> & m, std::string pathName);
    ```
    然后，再到MainView.cpp中，去实现每一个函数。
    ```c++
    #include "MainView.h"
    /* 欢迎 */
    void MainView:: welcome() {}
    /* 显示菜单 */
    void MainView:: showMenu() {}
    /* view 显示所有学生 */
    void MainView:: showAllStuAtView(const std::map<int, Student> & stu_m1 ){}
    /* view层 添加一个学生 */
    void  MainView:: addStuAtView( std::map<int, Student> & stu_m1 ){}
    /* view 查找一个学生 */
    void  MainView::  findStuAtView(const std::map<int, Student> & m1) {}
    /* view层删除一个学生 */
    void   MainView:: deleteByIdAtView(std::map<int, Student> & v1) {}
    /* view层 更新一个学生 */
    void   MainView:: updateByIdAtView(std::map<int, Student> & m1) {}
    /* view层 把vec保存进文件 */
    void   MainView:: saveToFileAtView(const std::map<int, Student> & m1, std::string pathName) {}
    /* view层 把文件中的东西导入 vec */
    void  MainView::  readFromFileAtView(std::map<int, Student> & m, std::string pathName) {}
    ```
4. main()函数入口
    main函数的开发，也就对照着需求的功能清单，把软件需要提供的功能，都列出来。我这里的设计思路是，用户输入#，软件退出，输入别的列出来的operateType，就执行相应功能。否则，就清屏，忽略用户的错误输入。在main函数里，针对用户不同操作类型的输入，调用业务类SFn中的成员函数，执行相应的操作。
    ```c++
    #include <iostream>
    #include <string>
    #include <map>
    #include "Student.h"
    #include "SFn.h"
    #include "MainView.h"
    using namespace std;

    int main() {
    string pathName = "d:/成绩.txt";
    map<int, Student> stu_v1;
    MainView view;
    view.welcome();
    view.showMenu();
    string operateType;
    cin>>operateType;
    while (operateType!="#")
    {
        if (operateType=="1") {view.addStuAtView(stu_v1);}// 录入
        else if(operateType=="2") {view.updateByIdAtView(stu_v1);}// 修改
        else if(operateType=="3") {view.findStuAtView(stu_v1);}// 查找
        else if (operateType=="4") {view.deleteByIdAtView(stu_v1);}
        else if( operateType == "5") {view.showAllStuAtView(stu_v1);}// 显示所有
        else if( operateType=="6") {view.saveToFileAtView(stu_v1,pathName);}// 保存至文件
        else if(operateType=="7") {view.readFromFileAtView(stu_v1,pathName);}// 从文件读取
        else { view.welcome(); view.showMenu();}
        cin>>operateType;
    }
    return 0;
### 4.2 填入代码
1. 实现View层的MainView类中的每个函数main函数的开发，也就对照着需求的功能清单，把软件需要提供的功能，都列出来。我这里的设计思路是，用户输入#，软件退出，输入别的列出来的operateType，就执行相应功能。否则，就清屏，忽略用户的错误输入。在main函数里，针对用户不同操作类型的输入，调用业务类SFn中的成员函数，执行相应的操作。</br> 
    ```c++
    #include "MainView.h"
    /* 欢迎 */
    void MainView::welcome()
    {
        system("cls");
        std::cout << "学籍信息管理系统" << std::endl;
    }
    //显示菜单
    void MainView::showMenu()
    {
        std::cout << std::endl;
        std::cout << "操作步骤：" << std::endl;
        std::cout << "1. 录入信息" << std::endl;
        std::cout << "2. 修改信息" << std::endl;
        std::cout << "3. 查找信息" << std::endl;
        std::cout << "4. 删除信息" << std::endl;
        std::cout << "5. 显示所有" << std::endl;
        std::cout << "6. 保存文件" << std::endl;
        std::cout << "7. 导入文件" << std::endl;
        std::cout << std::endl;
        std::cout << "作者：JYHan" << std::endl;
        std::cout << "2021/07/16" << std::endl;
        std::cout << "请选择操作：";
    }
    //view显示所有的学生
    void MainView::showAllStuAtView(const std::map<int, Student>& stu_m1)
    {
        system("cls");
        std::cout << "学号		" << "姓名		" << "成绩		" << std::endl;
        SFn Stu;
        Stu.showAll(stu_m1);
        system("pause");
        system("cls");
        welcome();
        showMenu();
    }
    //view添加学生信息
    void MainView::addStuAtView(std::map<int, Student>& stu_m1)
    {
        SFn SFnstu;
        int id;
        std::string name;
        double score;
        Student Studentstu;
        system("cls");
        std::cout << "录入\n";
        std::cout << "id:";
        std::cin >> id;
        std::cout << "name:";
        std::cin >> name;
        std::cout << "score:";
        std::cin >> score;
        Studentstu.setID(id);
        Studentstu.setName(name);
        Studentstu.setScore(score);
        //保存
        SFnstu.addStu(stu_m1, Studentstu);
        system("cls");
        welcome();
        showMenu();
    }
    //view查找学生信息
    void MainView::findStuAtView(const std::map<int, Student>& m1)
    {
        system("cls");
        std::cout << "请输入需要查找的学生的学号：" << std::endl;
        int id;
        std::cin >> id;
        Student Studentstu;
        SFn SFnstu;
        Studentstu = SFnstu.findStuById(m1, id);
        if (Studentstu.getID() != -1)
        {
            std::cout << Studentstu << std::endl;
        }
        else
        {
            std::cout << "查无此人！" << std::endl;
        }
        system("pause");
        system("cls");
        welcome();
        showMenu();
    }
    //view删除学生信息
    void MainView::deleteStuAtView(std::map<int, Student>& v1)
    {
        system("cls");
        std::cout << "请输入需要删除学生的学号：" << std::endl;
        int id;
        std::cin >> id;
        SFn SFnstu;
        bool b = SFnstu.deleteStuById(v1, id);
        if (b)
        {
            std::cout << "删除成功" << std::endl;
        }
        else
        {
            std::cout << "查无此人" << std::endl;
        }
    }
    //view更新学生信息
    void MainView::updateStuAtView(std::map<int, Student>& m1)
    {
        system("cls");
        std::cout << "请输入需要修改的学生的学号：" << std::endl;
        int id;
        std::cin >> id;
        std::string name;
        std::cout << "name:";
        std::cin >> name;
        double score;
        std::cout << "score:";
        std::cin >> score;
        Student Studentstu;
        Studentstu.setID(id);
        Studentstu.setName(name);
        Studentstu.setScore(score);
        SFn SFnstu;
        Student Studentstu_ = SFnstu.updateStu(m1, Studentstu);
        if (Studentstu_.getID() != -1)
        {
            std::cout << Studentstu_ << std::endl;
            std::cout << "修改成功" << std::endl;
        }
        else
        {
            std::cout << "查无此人" << std::endl;
        }
        system("pause");
        system("cls");
        welcome();
        showMenu();
    }
    //把map保存进文件
    void MainView::saveToFileAtView(const std::map<int, Student>& m1, std::string pathName)
    {
        if (m1.begin() == m1.end())
        {
            system("cls");
            std::cout << "还没有任何学生的信息，无法保存！" << std::endl;
        }
        else
        {
            //baocun
            SFn SFnstu;
            bool b = SFnstu.saveToFile(m1, pathName);
            if (b)
            {
                system("cls");
                std::cout << "保存成功" << std::endl;
            }
            else
            {
                std::cout << "保存失败！" << std::endl;
            }
        }
        system("pause");
        system("cls");
        welcome();
        showMenu();
    }
    //把文件中的东西导入到map
    void MainView::readFromAtView(std::map<int, Student>& m, std::string pathName)
    {
        system("cls");
        SFn SFnstu;
        bool b = SFnstu.readFromFile(m, pathName);
        if (b)
        {
            std::cout << "读取成功" << std::endl;
        }
        else
        {
            std::cout << "读取失败！" << std::endl;
        }
        system("pause");
        system("cls");
        welcome();
        showMenu();
    }
    ```
    &emsp;&emsp;View层用来提示用户并接收用户的输入，把用户输入的数据封装。调用SFn（业务层）的函数，以实现某种功能。比如说用户要查找信息，则输入一个待找学生的学号，View层的MainView接收到这个id以后，调用业务层SFn的findStuById的函数，查找一个学生。如果找到了，就把这个学生的信息打印在屏幕上。如果没有找到，就提示没有找到这个人。为了区分是否找到某个指定的学生，最开始在Student类的构造函数中，先把学生的id设置为-1，认为是无效学生。如果查询回来的学生的id是-1，其实意味着没有找到这个学生。
    在视图View层里，程序已经在调用Service层SFn这个类里的成员函数了。实际上，这些成员函数还没有写出来。现在继续填写。
    ```c++
    #include "SFn.h"
    #include "Student.h"
    #include <iostream>
    #include <map>
    #include <string>
    #include <fstream>
    #include <sstream>
    SFn::SFn(){}
    SFn::~SFn(){}
    //功能实现：增删查改
    //1. 增加
    Student SFn:: addStu(std::map<int, Student>& m1, Student& stu){
        m1.insert(std::make_pair(stu.getID(), stu));
        return stu;}
    //2. 删除
    bool SFn::deleteStuById(std::map<int, Student>& m1, const int& id){
        bool b = false;
        std::map<int, Student>::iterator iter;
        iter = m1.find(id);
        if (iter != m1.end()){
            m1.erase(iter);
            b = true;//删除成功}
        return b;}
    //3. 查找
    Student SFn::findStuById(const std::map<int, Student>& m1, const int& id){
        Student stu;
        std::map<int, Student>::const_iterator iter;
        iter = m1.find(id);
        if (iter != m1.end()){
            stu = iter->second;}
        return stu;}
    //4. 改动
    Student SFn::updateStu(std::map<int, Student>& m1, const Student& cstu){
        Student stu;
        int id = cstu.getID();
        std::map<int, Student>::iterator iter;
        iter = m1.find(id);
        if (iter != m1.end()) {
            //修改
            iter->second = cstu;
            stu = cstu;}
        return stu;}
    //显示全部
    void SFn::showAll(const std::map<int, Student>& m1) const{
        for (auto p : m1)//p??{
            std::cout << p.second << std::endl;}}
    //保存
    bool SFn::saveToFile(const std::map <int, Student>& m1, const std::string& pathName) const{
        bool b = true;
        std::fstream ofs(pathName, std::ios::out);
        if (ofs){
            std::stringstream ss;
            std::cout << "文件打开" << std::endl;
            Student stu;
            for (auto p = m1.begin(); p != m1.end(); p++){
                stu = p->second;
                ss << stu << std::endl;}
            ofs << ss.str();
            ofs.close();}
        else{
            std::cout << "文件打开失败！" << std::endl;
            b = false;}
        return b;}
    //读取
    bool SFn::readFromFile(std::map<int, Student>& m1, std::string path){
        bool b = true;
        m1.clear();
        std::fstream ifs(path,std::ios::in);
        if (ifs){
            std::cout << "文件打开" << std::endl;
            std::string s;
            std::stringstream ss;
            while (getline(ifs, s)){
                Student stu;
                ss << s;
                ss >> stu;
                ss.clear();
                m1.insert(std::make_pair(stu.getID(), stu));}
            ifs.close();}
        else{
            std::cout << "文件打开失败！" << std::endl;
            b = false;}
        return b;}
    ```
### 4.3 测试代码
![主界面]("/../img/SIMS-main.jpg")  
![录入界面]("/../img/SIMS-录入.jpg")  
![查询界面]("/../img/SIMS-查询.jpg")  
![修改界面]("/../img/SIMS-修改.jpg")  
![文件导入界面]("/../img/SIMS-导入文件.jpg")  
![文件保存界面]("/../img/SIMS-保存文件.jpg")   
![显示界面]("/../img/SIMS-显示.jpg")  
## 五、 总结
&emsp;&emsp;本文对一个较为完整的C++项目（“学生信息管理系统”，比较详细地介绍了当时写代码时，整个构思，以及实现的过程。
尽管项目比较小，本文还是用了分层设计的思想（比较传统的、经典的MVC框架模式）。
### 5.1. MVC  
&emsp;&emsp;MVC就是Model View Controller，是模型(model)－视图(view)－控制器(controller)的缩写，一种软件设计典范，用一种业务逻辑、数据、界面显示分离的方法组织代码，将业务逻辑聚集到一个部件里面，在改进和个性化定制界面及用户交互的同时，不需要重新编写业务逻辑。MVC被独特的发展起来用于映射传统的输入、处理和输出功能在一个逻辑的图形化用户界面的结构中。
MVC开始是存在于桌面程序中的，M是指业务模型，V是指用户界面，C则是控制器，使用MVC的目的是将M和V的实现代码分离，从而使同一个程序可以使用不同的表现形式。比如一批统计数据可以分别用柱状图、饼图来表示。C存在的目的则是确保M和V的同步，一旦M改变，V应该同步更新。
### 5.2. 框架和设计模式的区别  
&emsp;&emsp;有很多程序员往往把框架模式和设计模式混淆，认为MVC是一种设计模式。实际上它们完全是不同的概念。
框架、设计模式这两个概念总容易被混淆，其实它们之间还是有区别的。框架通常是代码重用，而设计模式是设计重用，架构则介于两者之间，部分代码重用，部分设计重用，有时分析也可重用。在软件生产中有三种级别的重用：内部重用，即在同一应用中能公共使用的抽象块;代码重用，即将通用模块组合成库或工具集，以便在多个应用和领域都能使用；应用框架的重用，即为专用领域提供通用的或现成的基础结构，以获得最高级别的重用性。
框架与设计模式虽然相似，但却有着根本的不同。设计模式是对在某种环境中反复出现的问题以及解决该问题的方案的描述，它比框架更抽象；框架可以用代码表示，也能直接执行或复用，而对模式而言只有实例才能用代码表示;设计模式是比框架更小的元素，一个框架中往往含有一个或多个设计模式，框架总是针对某一特定应用领域，但同一模式却可适用于各种应用。可以说，框架是软件，而设计模式是软件的知识。
### 5.3. 框架模式有哪些？  
&emsp;&emsp;MVC、MTV、MVP、CBD、ORM等等；
### 5.4. 框架有哪些？  
&emsp;&emsp;C++语言的QT、MFC、gtk，Java语言的SSH 、SSI，php语言的smarty(MVC模式)，python语言的django(MTV模式)等等
### 5.5. 设计模式有哪些？  
&emsp;&emsp;工厂模式、适配器模式、策略模式等等.简而言之：框架是大智慧，用来对软件设计进行分工；设计模式是小技巧，对具体问题提出解决方案，以提高代码复用率，降低耦合度。
## 六、 CMake组织管理
### 6.1 CMake
&emsp;&emsp;makefile是在Linux编译c或者c++代码的时候的一种脚本文件，但是每一个功能都要写一个makefile文件，这样如果这个工程很大，而且相关性比较强的话，makefile的书写就会变得相对繁琐，更要命的是如果以后需要添加新的功能或者是新人需要修改功能的话，看起来就会特别麻烦；因为介于此，CMake的出现就是为了解决这样的问题，CMake的入门相当容易，而且管理也特别方便简单。【CMake是一种跨平台的开源项目管理工具，所做的事其实就是告诉编译器如何去编译链接源代码。与之相似的是直接编写makefile文件，但makefile最大的缺点就是不能跨平台，一旦更换环境就要重新编写，于是我们可以使用CMake编写CMakeLists文件来解决此问题。】  
&emsp;&emsp;CMake的所有语句都写在一个CMakeLists.txt的文件中，CMakeLists.txt文件确定后，直接使用cmake命令进行运行，但是这个命令要指向CMakeLists.txt所在的目录，cmake之后就会产生我们想要的makefile文件，然后再直接make就可以编译出我们需要的结果了。更简单的解释就是cmake是为了生成makefile而存在，这样我们就不需要再去写makefile了，只需要写简单的CMakeLists.txt即可。
```cmake  
# 1.cmake verson，指定cmake版本 
cmake_minimum_required(VERSION 3.0)
# 2.project name，指定项目的名称，一般和项目的文件夹名称对应
PROJECT(SIMS)
# 3.head file path，头文件目录
INCLUDE_DIRECTORIES(include)
# 4.source directory，源文件目录
AUX_SOURCE_DIRECTORY(src DIR_SRCS)
# 5.set environment variable，设置环境变量，编译用到的源文件全部都要放到这里，
SET(TEST_MATH ${DIR_SRCS})
# 6.add executable file，添加要编译的可执行文件
ADD_EXECUTABLE(${PROJECT_NAME} ${TEST_MATH})
```
如果需要添加依赖库，也可以在CMakeLists.txt写进去。

### 6.2 Anaconda
根据.yml依赖文件在自己的环境下面配置代码中所需要的库包。
```cmd
conda env create -n JYHan -f environment.yml
conda activate JYHan
```
然后使用windows批处理命令build.bat进行编译
```bat
mkdir build
cd build

cmake -G "Visual Studio 16 2019" -A x64 ^
      ../
```
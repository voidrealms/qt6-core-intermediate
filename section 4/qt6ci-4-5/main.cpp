/*
    What
    Parent child relationships

    Why
    QObject built in memory managment

    How
    Making an object tree

*/


#include <QCoreApplication>
#include "test.h"

Test* makeTree()
{
    Test* root = new Test(nullptr,"Root");

    for(int p = 0; p < 5; p++)
    {
        Test* pobj = new Test(root,"Parent-" + QString::number(p));

        for(int c = 0; c < 3; c++)
        {
            Test* cobj = new Test(pobj,"Child-"  + QString::number(p) + " " + QString::number(c));
            for(int s = 0; s < 3; s++)
            {
                Test* sobj = new Test(cobj,"Sub-"  + QString::number(p) + " " + QString::number(c)  + " " + QString::number(s));
                Q_UNUSED(sobj);
            }
        }
    }

    return root;
}

void printTree(Test* root, int level = 0)
{
    if(root->children().length() == 0) return;

    QString lead = "-";
    lead.fill('-', level * 5);

    foreach(QObject* obj, root->children())
    {
        Test* child = qobject_cast<Test*>(obj);
        if(!child) return;

        qInfo() << lead << child;

        printTree(child,level + 1);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test* tree = makeTree();
    printTree(tree,1);
    delete tree;

    return a.exec();
}

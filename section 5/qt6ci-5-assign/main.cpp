/*

  What
  Assignment

  Why
  Practice what you have learned

  Example:
  Add items and find the index of an item to display it

 */

#include <QCoreApplication>
#include <QList>

QList<int> makeList()
{
    QList<int> items;

    for(int i = 0; i < 20; i++)
    {
        items.append(i * 3);
    }

    return items;
}

void find(QList<int> &list, int value)
{
    int pos = list.indexOf(value);
    if(pos < 0)
    {
        qInfo() << "Item not found";
        return;
    }

    qInfo() << "At:" << pos << "Value" << list.at(pos);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list = makeList();
    qInfo() << list;
    find(list,9);

    return a.exec();
}

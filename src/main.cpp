
#include <FenetrePrincipale/FenetrePrincipale.hpp>

#include <QApplication>
#include <QDir>

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

	Q_INIT_RESOURCE(resource);

  TestCompil::FenetrePrincipale::MainWindow fenetre;
  fenetre.show();

  return app.exec();
}
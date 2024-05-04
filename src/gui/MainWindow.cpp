
#include "MainWindow.hpp"

#include <gui/Interrogation.hpp>

#include <data/Interrogation.hpp>

#include <QVBoxLayout>

namespace NomCool::gui {

MainWindow::MainWindow()
{
	mMainLayout = new QGridLayout();

	// This row is reserved for the previous result widget
	// The next one should be added at the mPreviousResultPosition.first + 1
	mPreviousResultPosition = {mMainLayout->rowCount(), 0};

	// This row is reserved for the interrogation widget
	// The next one should be added at the mInterrogationPosition.first + 1
	mInterrogationPosition = {mPreviousResultPosition.first + 1, 0};

	auto* centralWidget = new QWidget();
	centralWidget->setLayout(mMainLayout);
	setCentralWidget(centralWidget);
}

void MainWindow::setInterrogation(const data::Interrogation& interrogation)
{
	if (mInterrogation)
	{
		mMainLayout->removeWidget(mInterrogation);
		delete mInterrogation;
	}	
	mInterrogation = new Interrogation(interrogation);
	connect(mInterrogation, &Interrogation::responseSelected, this, &MainWindow::responseSelected);
	mMainLayout->addWidget(mInterrogation, mInterrogationPosition.first, mInterrogationPosition.second);
}

void MainWindow::setPreviousResult(const data::Result& result)
{
	if (mPreviousResult)
	{
		mMainLayout->removeWidget(mPreviousResult);
		delete mPreviousResult;
	}	
	mPreviousResult = new PreviousResult(result);
	mMainLayout->addWidget(mPreviousResult, mPreviousResultPosition.first, mPreviousResultPosition.second);
}

} // namespace NomCool::FenetrePrincipale


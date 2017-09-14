#include "gui.h"

Gui::Gui()
{
	queryEdit = new QTextEdit();

	setCentralWidget(queryEdit);

	createMenu();
	createDockWindows();

	setWindowTitle(tr("CROSS SQL QUERY"));

	setUnifiedTitleAndToolBarOnMac(true);
}

void Gui::createMenu()
{
	QToolBar *fileToolBar = addToolBar(tr("File"));

	const QIcon newIcon = QIcon::fromTheme("document-new", QIcon(":/images/new.png"));
	QAction *action_newConnection = new QAction(newIcon, tr("&Add new connection"));

	action_newConnection->setStatusTip(tr("Create a new connection"));
	connect(action_newConnection, &QAction::triggered, this, &Gui::addConnection);
	fileToolBar->addAction(action_newConnection);

	const QIcon saveIcon = QIcon::fromTheme("document-save", QIcon(":/images/delete.png"));
	QAction *action_deleteConnection = new QAction(saveIcon, tr("&Delete selected connection"));

	action_deleteConnection->setStatusTip(tr("Delete selected connection"));
	connect(action_deleteConnection, &QAction::triggered, this, &Gui::deleteConnction);
	fileToolBar->addAction(action_deleteConnection);

	QToolBar *run = addToolBar(tr("Run query"));

	const QIcon runIcon = QIcon::fromTheme("document-new", QIcon(":/images/run.png"));
	QAction *action_run_query = new QAction(runIcon, tr("&Run query"));

	action_run_query->setStatusTip(tr("Run query"));
	connect(action_run_query, &QAction::triggered, this, &Gui::run_query);

	run->addAction(action_run_query);
}

void Gui::createDockWindows()
{
	// create Dock for connections
	QDockWidget* connection_dock = new QDockWidget(tr("Connections"), this);
	connection_dock->setAllowedAreas(Qt::LeftDockWidgetArea);

	connectionList = new QListWidget(connection_dock);
	connectionList->addItems(QStringList()
		<< "Connection1"
		<< "Connection2");

	connection_dock->setWidget(connectionList);
	addDockWidget(Qt::LeftDockWidgetArea, connection_dock);

	// create Dock for Table
	QDockWidget* result_dock = new QDockWidget(tr("Result"), this);
	result_dock->setAllowedAreas(Qt::BottomDockWidgetArea | Qt::TopDockWidgetArea);

	resultTable = new QTableWidget(25, 25, result_dock);

	result_dock->setWidget(resultTable);
	addDockWidget(Qt::BottomDockWidgetArea, result_dock);
}

void Gui::about()
{
	QMessageBox::about(this, tr("CROSS"),
		tr("Write here about CROSS"));
}

void Gui::addConnection()
{
	QDialog *dialog = new QDialog();
	QFormLayout *form = new QFormLayout();

	QComboBox *input_db = new QComboBox();
	input_db->addItems(QStringList() << "PostgreSQL" << "MySQL");

	QLineEdit *input_name = new QLineEdit();
	QLineEdit *input_host = new QLineEdit();
	QLineEdit *input_port = new QLineEdit();
	QLineEdit *input_login = new QLineEdit();
	QLineEdit *input_password = new QLineEdit();

	form->addRow(new QLabel("Connection details"));

	form->addRow("Connection name", input_name);
	form->addRow("DB type", input_db);
	form->addRow("Host:", input_host);
	form->addRow("Port:", input_port);
	form->addRow("Login:", input_login);
	form->addRow("Password:", input_password);

	QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

	QObject::connect(buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
	QObject::connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));
	form->addWidget(buttonBox);

	dialog->setLayout(form);

	int result = dialog->exec();
	if(result == QDialog::Accepted)
	{
		/*add new connection*/
		QString name = input_name->text();
		QString type = input_db->currentText();

		connectionList->addItem(name);
		int r = connectionList->count() - 1;
		connectionList->setCurrentRow(r);
	}
}

void Gui::deleteConnction()
{
	int r = connectionList->currentRow();

	if (r != -1) {
		/* delete selected connection name */
		QListWidgetItem *item = connectionList->takeItem(r);
		QString connection_name = item->toolTip();

		delete item;
	}
}

void Gui::run_query()
{
	const QString query = queryEdit->toPlainText();
}

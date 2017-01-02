#ifndef myDialog_H
#define myDialog_H

#include <QDialog>
#include "ui_gui.h"
#include "functions/downloader.h"
#include "functions/yt_functions.h"

// a really fat class:
class myDialog : public QDialog, public Ui::Form, public downloader, public yt_functions
//FIXME: unnecessarily creates multiple instance of the classes
//inherited. After porting/linking the core functions into gui, re-plan
//to better connect everything
{
	Q_OBJECT

	public:
		myDialog(QWidget * parent = 0);
		void perform_downloads(vector<string> & downloaded_pages); // overriding
		string generate_html(); // overriding virtual
		string subscribe(string url); // overriding virtual

	public slots:
		void open_firefox();
		void sub_clicked();
		void list_clicked();
		void generate_clicked();
		void genOpenClicked();
	
	protected:
		QString url;
};

#endif

#include "myDialog.h"
//#include <cstdlib>

#include <iostream> // infos for terminal run
#include <QDesktopServices> // openurl
#include <QUrl> // needed for openurl

#include <QApplication> // process emits before moving on
#include <QFileInfo> // check if file exists

using std::cout;

myDialog::myDialog(QWidget * parent) : QDialog(parent)
{
	setupUi(this);

	listBrowser->setEnabled(false);
	listBrowser->setOpenExternalLinks(true);

	this->adjustSize();

	QObject::connect(
			openButton, SIGNAL(clicked()),
			this, SLOT(open_firefox())
			);

	QObject::connect(
			subButton, SIGNAL(clicked()),
			this, SLOT(sub_clicked())
			);

	QObject::connect(
			generateButton, SIGNAL(clicked()),
			this, SLOT(generate_clicked())
			);

	QObject::connect(
			genOpenButton, SIGNAL(clicked()),
			this, SLOT(genOpenClicked())
			);

	emit list_clicked();
}

void myDialog::genOpenClicked()
{
	emit generate_clicked();
	emit open_firefox();
}

void myDialog::generate_clicked()
{
	emit infoLabel->setVisible(true);
	emit infoLabel->setText("Downloading...");

	emit generateButton->setEnabled(false);
	emit genOpenButton->setEnabled(false);
	emit subButton->setEnabled(false);
	emit openButton->setEnabled(false);
	emit listBrowser->setEnabled(false);

	QApplication::processEvents();

	string result = generate_html();
	if(result.size() < 2)
	{
		// x - downloaded_pages.size() == 0
		// y - vid_vec.size() == 0
		emit infoLabel->setText("<font color='red'>Error on download</font>");
	}
	else
	{
		emit infoLabel->setText(result.c_str());
		emit list_clicked();
	}

	emit generateButton->setEnabled(true);
	emit genOpenButton->setEnabled(true);
	emit subButton->setEnabled(true);
	emit openButton->setEnabled(true);
	emit listBrowser->setEnabled(true);
}

void myDialog::list_clicked()
{
	emit infoLabel->setVisible(true);

	QApplication::processEvents();

	QString theList(sub_list().c_str());

	if(theList.size() == 0)
	{
		emit infoLabel->setText("<font color='red'>&nbsp;Error: no .dat file, (start subscribing?)</font>");
		emit listBrowser->clear();
		emit listBrowser->setEnabled(false);
	}
	else
	{
		emit listBrowser->setEnabled(true);
		emit listBrowser->setText(theList);
	}
}

void myDialog::sub_clicked()
{
	if(lineEdit->text().size() > 11)
	{
		url = lineEdit->text();
		emit infoLabel->setText("Downloading data...");
		emit infoLabel->setVisible(true);

		QApplication::processEvents();

		string result = subscribe(url.toStdString());

		QString text_for_label;


		// "" -- no youtube.com
		// "?" -- couldn't extract info
		// "x" -- unknown error
		// else string
		if(result.size() < 2)
		{
			if(result == "")
			{ text_for_label = "<font color='red'>Invalid Url</font>"; }
			else if(result == "?")
			{ text_for_label = "<font color='red'>Couldn't download/extract info</font>"; }
			else if(result == "c")
			{ text_for_label = "<font color='red'>Couldn't open file to write info</font>"; }
			else
			{ text_for_label = "<font color='red'>Unknown error</font>"; }
		}
		else
		{
			text_for_label = result.c_str();
			emit list_clicked();
		}

		emit infoLabel->setText(text_for_label);
	}
	else
	{
		emit infoLabel->setText("<font color='red'>&nbsp;Error: invalid url</font>");
		emit infoLabel->setVisible(true);
	}
}

void myDialog::open_firefox()
{
	QFileInfo a_file("yt_view_subscription.html");
	if(a_file.exists() && a_file.isFile())
	{
		if(infoLabel->text() == "<font color='red'>Error on download</font>")
		{
			emit infoLabel->setText("<font color='red'>Download Error, use Open button for old HTML</font>");
		}
		else
		{
			if(QDesktopServices::openUrl(QUrl("yt_view_subscription.html")))
			{
				emit infoLabel->setText("Opened!");
			}
			else
			{
				emit infoLabel->setText("<font color='red'>&nbsp;Error: Couldn't open</font>");
			}
		}
	}
	else
	{
		emit infoLabel->setText("<font color='red'>&nbsp;Error: no generated html found</font>");
	}

	emit infoLabel->setVisible(true);
}


// --- overloaded(99.9% copy of original) member function begins ----


// overloading to use this->perform_downloads()
// for progressbar
string myDialog::generate_html()
{
	inFile.close();

	inFile.open("yt_sub_list.dat");
	if(!inFile.good())
	{
		inFile.close();
		return "Error: couldn't open data file";
	}

	string url;
	this->clear_url(); // <--
	while(getline(inFile, channelID) && getline(inFile, channelName) && getline(inFile, a_page))
	{
		url  = "https://www.youtube.com/feeds/videos.xml?channel_id=";
		url += channelID;
		this->add_url(url); // <--
	}
	inFile.close();
	downloaded_pages.clear();
	this->perform_downloads(downloaded_pages); // <--- for this

	if(downloaded_pages.size()) { cout << "--Extracting information...\n"; }
	else { return "x"; }

	vid_vec.clear();
	string timeStr;
	for(size_t i = 0; i < downloaded_pages.size(); ++i)
	{
		while(downloaded_pages[i].find(a.c_str()) != string::npos)
		{
			vid_info one;
			one.vid_id    = yt_p.parse(a, abc_end, downloaded_pages[i], true);
			timeStr       = yt_p.parse(b, abc_end, downloaded_pages[i], true);
			one.vid_time_unix = yt_p.timeStr_to_unix_t(timeStr);
			one.vid_title = yt_p.parse(c, abc_end, downloaded_pages[i], true);

			vid_vec.push_back(one);
		}
	}

	// sort vector by time, small to large
	std::sort(vid_vec.begin(), vid_vec.end(), vecTimeCompare);

	if(vid_vec.size() == 0) return "y"; // assuming it's downloader's issue

	outFile.open("yt_view_subscription.html");
	if(outFile.good())
	{
		cout << "--Generating html\n";
		full = html_pre;
		a_id = "";

		size_t i_end = vid_vec.size();

		for(size_t i = 0; i < i_end; ++i)
		{
			a_id = vid_vec[i].vid_id;

			full += section_a;
			full += a_id;
			full += section_b;
			full += section_c;
			full += a_id;
			full += section_d;
			full += a_id;
			full += section_e;
			full += vid_vec[i].vid_title;
			full += section_f;
		}

		full += html_post;

		outFile << full;

	}

	outFile.close();

	return "Updated HTML generation complete";
}

// overloading to use progressBar, using same this as generate
string myDialog::subscribe(string url)
{
	if(url.find("youtube.com") == string::npos) { return ""; }

	this->clear_url(); // <---
	this->add_url(url); // <---
	downloaded_pages.clear();
	this->perform_downloads(downloaded_pages); // <--

	channelName = "";
	channelID   = "";

	if(downloaded_pages.size() != 0)
	{
		a_page = downloaded_pages[0];

		channelID = yt_p.parse("data-channel-external-id=\"", "\"", a_page);

		if(url.find("/user/") != string::npos)
		{
			channelName = yt_p.parse(
					"<meta name=\"title\" content=\"",
					"\"",
					a_page);
		}
		else if(url.find("/channel/") != string::npos)
		{
			channelName = yt_p.parse(
					"<meta property=\"og:title\" content=\"",
					"\"",
					a_page);
		}
		else
		{
			channelName = yt_p.parse(
					"\"author\":\"",
					"\"",
					a_page);
		}
	}

	if(channelName == "" || channelID == "") { return "?"; }
	else
	{
		inFile.open("yt_sub_list.dat");
		if(inFile.good())
		{
			string line;
			while(getline(inFile, line))
			{
				if(line == channelID)
				{
					return "Already subscribed :)\n";
				}
			}
		}
		inFile.close();

		outFile.open("yt_sub_list.dat", std::ios::app);
		if(outFile.good())
		{
			outFile
				<< channelID
				<< '\n'
				<< channelName
				<< "\n\n";
		}
		else
		{
			outFile.close();
			return "c";
		}
		outFile.close();
		string outPut;
		outPut += "Subscribed to: ";
		outPut += channelName;
		outPut += "\n";
		return outPut;
	}

	return "x";
}

// overloading for progressBar
void myDialog::perform_downloads(vector<string> & downloaded_pages)
{
	if(!good_to_go) { good_to_go = true; return; }

	size_t i_end = string_urls.size();

	emit progressBar->setMinimum(0);
	emit progressBar->setMaximum(i_end);
	emit progressBar->setValue(0);
	QApplication::processEvents();

	for(size_t i = 0; i < i_end; ++i)
	{
		check(curl_easy_setopt(ez_handle, CURLOPT_URL, string_urls[i].c_str()));
		if(!good_to_go) { good_to_go = true; emit progressBar->setValue(i_end); return; }

		downloaded_page = "";
		check(curl_easy_perform(ez_handle));

		emit progressBar->setValue(i+1); // <---
		cout << "--Download progress: " << i+1 << " of " << i_end << '\n';

		downloaded_pages.push_back(downloaded_page);
	}
}

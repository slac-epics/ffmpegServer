#ifndef FFMPEGVIEWER_H
#define FFMPEGVIEWER_H

#include <QGLWidget>
#include <QThread>
#include <QWheelEvent>
#include <QtDesigner/QDesignerExportWidget>
#include <QSpinBox>

/* ffmpeg includes */
extern "C" {
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "libavutil/avutil.h"
}

#define MAXWIDTH 1024
#define MAXHEIGHT 768

class FFThread : public QThread
{
    Q_OBJECT

public:
    FFThread (const QString &url, unsigned char* destFrame, QWidget* parent = 0);
    ~FFThread ();
    void run();    

public slots:
    void stopGracefully() { stopping=1; }

signals:
    void updateSignal(int imw, int imh, bool firstImage);
    
private:
    char *url;
    QByteArray ba;
    int stopping, maxW, maxH;
    AVFrame             *pFrame;     
    AVFrame             *pFrameRGB;         
    uint8_t             *buffer;    
    unsigned char* destFrame;
};

class QDESIGNER_WIDGET_EXPORT ffmpegViewer : public QGLWidget
{
	Q_OBJECT
    Q_PROPERTY( int x READ x WRITE setX)
    Q_PROPERTY( int y READ y WRITE setY)
    Q_PROPERTY( int zoom READ zoom WRITE setZoom)    
    Q_PROPERTY( int gx READ gx WRITE setGx)
    Q_PROPERTY( int gy READ gy WRITE setGy)
    Q_PROPERTY( int gs READ gs WRITE setGs)
    Q_PROPERTY( bool grid READ grid WRITE setGrid)    
    Q_PROPERTY( QString url READ url WRITE setUrl)  
          

public:
	ffmpegViewer (QWidget* parent = 0);
	ffmpegViewer (const QString &url, QWidget* parent = 0);
	~ffmpegViewer ();

    int x() const           { return _x; }
    int y() const           { return _y; }
    int maxX() const        { return _maxX; }
    int maxY() const        { return _maxY; }            
    int zoom() const        { return _zoom; }    
    int gx() const          { return _gx; }
    int gy() const          { return _gy; }
    int maxGx() const       { return _maxGx; }
    int maxGy() const       { return _maxGy; }                
    int gs() const          { return _gs; }
    QColor gcol() const     { return _gcol; }
    bool grid() const       { return _grid; }
    QString url() const     { return _url; }
    
signals:
    void xChanged(int x);
    void yChanged(int y);
    void maxXChanged(int maxX);
    void maxYChanged(int maxY);            
    void zoomChanged(int zoom);    
    void gxChanged(int gx);
    void gyChanged(int gy);
    void maxGxChanged(int maxGx);
    void maxGyChanged(int maxGy);                
    void gsChanged(int gs);    
//    void gcolChanged(QColor gcol);
    void gridChanged(bool grid);    
    void urlChanged(const QString &);

    void aboutToQuit();

public slots:
    void setX(int x);
    void setY(int y);
    void setZoom(int zoom);    
    void setGx(int gx);
    void setGy(int gy);
    void setGs(int gs);
    void setGcol();
    void setGrid(bool grid);    
    void setUrl(const QString &url);
    void setReset();    
    void ffInit();
	void updateImage (int imw, int imh, bool firstImage);	

protected:
	void initializeGL ();
	void paintGL ();
	void resizeGL (int width, int height);
	void mousePressEvent (QMouseEvent* event);
	void mouseMoveEvent (QMouseEvent* event);	
	void mouseDoubleClickEvent (QMouseEvent* event);	
    void wheelEvent( QWheelEvent* );	
    void updateViewport();
    void ffQuit();       
    void init(); 

private:       
    int _x, _y, _maxX, _maxY, _zoom, _gx, _gy, _maxGx, _maxGy, _gs, _w, _h, _imw, _imh;
    bool _grid; 
    QString _url; 
    unsigned char* destFrame;
    QColor _gcol;
    unsigned int tex, qlist;
    int clickx, clicky, oldx, oldy;
    FFThread *ff;  
    bool disableUpdates;    
    
};

class SSpinBox : public QSpinBox
{
    Q_OBJECT

public:
    SSpinBox(QWidget *parent = 0);

public slots:
    void setMaximumSlot(int max) {setMaximum(max);}	
};

#endif
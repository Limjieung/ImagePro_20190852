
// ImagePro_20190852View.h: CImagePro20190852View 클래스의 인터페이스
//

#pragma once


class CImagePro20190852View : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	CImagePro20190852View() noexcept;
	DECLARE_DYNCREATE(CImagePro20190852View)

// 특성입니다.
public:
	CImagePro20190852Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CImagePro20190852View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPixelAdd();
	afx_msg void OnPixelSub();
	afx_msg void OnPixelHistoEq();
	afx_msg void OnPixelGob();
	afx_msg void OnPixelDiv();
	afx_msg void OnPixelContrastStretch();
	afx_msg void OnPixelBinarization();
	afx_msg void OnPixelTwoImagegAdd();
	void LoadTwoimage();
	afx_msg void OnPixelTwoImageSub();
	afx_msg void OnRegionSmoothing();
	void Convolve(unsigned char** inimg, unsigned char** Outimg, int cols, int rows, float mask[][3] , int bias, int depth);
	afx_msg void OnRegionSharpening();
	afx_msg void OnRegionEmbosing();
	afx_msg void OnRegionPrewitt();
	afx_msg void OnRegionRoberts();
	afx_msg void OnRegionSobel();
	afx_msg void OnRegionAverageFiltering();
	afx_msg void OnRegionMedianFiltering();
	afx_msg void OnMopologyColorGray();
	afx_msg void OnMopologyBinarization();
	afx_msg void OnMopologyErosion();
	afx_msg void OnMopologyOpening();
	afx_msg void OnMopologyDilation();
	void CopyResultToInput();
	afx_msg void OnMopologyColsing();
	afx_msg void OnGeometryZoominPixelCopy();
	afx_msg void OnGeometryZoominBinarInterpolation();
	afx_msg void OnGeometryZoomout();
	afx_msg void OnGeometryZoomoutMeanSub();
	afx_msg void OnGeometryAvgFiltering();
	afx_msg void OnGeometryRotation();
};

#ifndef _DEBUG  // ImagePro_20190852View.cpp의 디버그 버전
inline CImagePro20190852Doc* CImagePro20190852View::GetDocument() const
   { return reinterpret_cast<CImagePro20190852Doc*>(m_pDocument); }
#endif



// ImagePro_20190852View.cpp: CImagePro20190852View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImagePro_20190852.h"
#endif

#include "ImagePro_20190852Doc.h"
#include "ImagePro_20190852View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImagePro20190852View

IMPLEMENT_DYNCREATE(CImagePro20190852View, CScrollView)

BEGIN_MESSAGE_MAP(CImagePro20190852View, CScrollView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_PIXEL_HISTO_EQ, &CImagePro20190852View::OnPixelHistoEq)
	ON_COMMAND(ID_Pixel_Gob, &CImagePro20190852View::OnPixelGob)
	ON_COMMAND(ID_Pixel_Add, &CImagePro20190852View::OnPixelAdd)
	ON_COMMAND(ID_Pixel_Sub, &CImagePro20190852View::OnPixelSub)
	ON_COMMAND(ID_Pixel_Div, &CImagePro20190852View::OnPixelDiv)
	ON_COMMAND(ID_PIXEL_CONTRAST_STRETCH, &CImagePro20190852View::OnPixelContrastStretch)
	ON_COMMAND(ID_PIXEL_BINARIZATION, &CImagePro20190852View::OnPixelBinarization)
	ON_COMMAND(ID_PIXEL_TWO_IMAGEG_ADD, &CImagePro20190852View::OnPixelTwoImagegAdd)
	ON_COMMAND(ID_PIXEL_TWO_IMAGE_SUB, &CImagePro20190852View::OnPixelTwoImageSub)
	ON_COMMAND(ID_REGION_SMOOTHING, &CImagePro20190852View::OnRegionSmoothing)
	ON_COMMAND(ID_REGION_SHARPENING, &CImagePro20190852View::OnRegionSharpening)
	ON_COMMAND(ID_REGION_EMBOSING, &CImagePro20190852View::OnRegionEmbosing)
	ON_COMMAND(ID_REGION_PREWITT, &CImagePro20190852View::OnRegionPrewitt)
	ON_COMMAND(ID_REGION_ROBERTS, &CImagePro20190852View::OnRegionRoberts)
	ON_COMMAND(ID_REGION_SOBEL, &CImagePro20190852View::OnRegionSobel)
	ON_COMMAND(ID_REGION_AVERAGE_FILTERING, &CImagePro20190852View::OnRegionAverageFiltering)
	ON_COMMAND(ID_REGION_MEDIAN_FILTERING, &CImagePro20190852View::OnRegionMedianFiltering)
	ON_COMMAND(ID_MOPOLOGY_COLOR_GRAY, &CImagePro20190852View::OnMopologyColorGray)
	ON_COMMAND(ID_MOPOLOGY_BINARIZATION, &CImagePro20190852View::OnMopologyBinarization)
	ON_COMMAND(ID_MOPOLOGY_EROSION, &CImagePro20190852View::OnMopologyErosion)
	ON_COMMAND(ID_MOPOLOGY_OPENING, &CImagePro20190852View::OnMopologyOpening)
	ON_COMMAND(ID_MOPOLOGY_DILATION, &CImagePro20190852View::OnMopologyDilation)
	ON_COMMAND(ID_MOPOLOGY_COLSING, &CImagePro20190852View::OnMopologyColsing)
	ON_COMMAND(ID_GEOMETRY_ZOOMIN_PIXEL_COPY, &CImagePro20190852View::OnGeometryZoominPixelCopy)
	ON_COMMAND(ID_GEOMETRY_ZOOMIN_BINAR_INTERPOLATION, &CImagePro20190852View::OnGeometryZoominBinarInterpolation)
	ON_COMMAND(ID_GEOMETRY_ZOOMOUT, &CImagePro20190852View::OnGeometryZoomout)
	ON_COMMAND(ID_GEOMETRY_ZOOMOUT_MEAN_SUB, &CImagePro20190852View::OnGeometryZoomoutMeanSub)
	ON_COMMAND(ID_GEOMETRY_AVG_FILTERING, &CImagePro20190852View::OnGeometryAvgFiltering)
	ON_COMMAND(ID_GEOMETRY_ROTATION, &CImagePro20190852View::OnGeometryRotation)
END_MESSAGE_MAP()

// CImagePro20190852View 생성/소멸

CImagePro20190852View::CImagePro20190852View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CImagePro20190852View::~CImagePro20190852View()
{
}

BOOL CImagePro20190852View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// CImagePro20190852View 그리기

void CImagePro20190852View::OnDraw(CDC* pDC)
{
	CImagePro20190852Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int x, y;
	if (pDoc->inputImg != NULL) 
	{
		if (pDoc->depth == 1) {
			for (y = 0; y < pDoc->imageHeight; y++)
				for (x = 0; x < pDoc->imageWidth; x++)
					pDC->SetPixel(x, y, RGB(pDoc->inputImg[y][x], pDoc->inputImg[y][x],
						pDoc->inputImg[y][x]));
		}

		else if
			(pDoc->depth == 3)
		{
			for (y = 0; y < pDoc->imageHeight; y++)
				for (x = 0; x < pDoc->imageWidth; x++)
					pDC->SetPixel(x, y, RGB(pDoc->inputImg[y][3 * x + 0], pDoc->inputImg[y][3 * x + 1],
						pDoc->inputImg[y][3 * x + 2]));
		} 
	}
	if (pDoc->resultImg != NULL) 
	{
		if (pDoc->depth == 1) {
			for (y = 0; y < pDoc->imageHeight; y++)
				for (x = 0; x < pDoc->imageWidth; x++)
					pDC->SetPixel(x + pDoc->imageWidth + 30, y, RGB(pDoc->resultImg[y][x], pDoc->resultImg[y][x],
						pDoc->resultImg[y][x]));
		}
		else if (pDoc->depth == 3)
		{
			for (y = 0; y < pDoc->imageHeight; y++)
				for (x = 0; x < pDoc->imageWidth; x++)
					pDC->SetPixel(x + pDoc->imageWidth + 30, y, RGB(pDoc->resultImg[y][3 * x + 0], pDoc->resultImg[y][3 * x + 1],
						pDoc->resultImg[y][3 * x + 2]));
		}
	}

	if (pDoc->inputImg2 != NULL)  
	{
		if (pDoc->depth == 1) {
			for (y = 0; y < pDoc->imageHeight; y++)
				for (x = 0; x < pDoc->imageWidth; x++)
					pDC->SetPixel(x + pDoc->imageWidth + 2 * 250, y, RGB(pDoc->inputImg2[y][x], pDoc->inputImg2[y][x],
						pDoc->inputImg2[y][x]));
		}
		else if (pDoc->depth == 3)
		{
			for (y = 0; y < pDoc->imageHeight; y++)
				for (x = 0; x < pDoc->imageWidth; x++)
					pDC->SetPixel(x + pDoc->imageWidth + 2 * 250, y, RGB(pDoc->inputImg2[y][3 * x + 0], pDoc->inputImg2[y][3 * x + 1],
						pDoc->inputImg2[y][3 * x + 2]));
		} 
	}
	if (pDoc->gresultImg != NULL)
	{
		if (pDoc->depth == 1) {
			for (y = 0; y < pDoc->gimageHeight; y++)
				for (x = 0; x < pDoc->gimageWidth; x++)
					pDC->SetPixel(x, y + pDoc->imageHeight + 20, RGB(pDoc->gresultImg[y][x], pDoc->gresultImg[y][x],
						pDoc->gresultImg[y][x]));
		}
		else if (pDoc->depth == 3)
		{
			for (y = 0; y < pDoc->gimageHeight; y++)
				for (x = 0; x < pDoc->gimageWidth; x++)
					pDC->SetPixel(x, y+ pDoc->imageHeight + 20, RGB(pDoc->gresultImg[y][3 * x + 0], pDoc->gresultImg[y][3 * x + 1],
						pDoc->gresultImg[y][3 * x + 2]));
		}
	}
}
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

void CImagePro20190852View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.
	sizeTotal.cx = 2048;
	sizeTotal.cy = 1024;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CImagePro20190852View 인쇄

BOOL CImagePro20190852View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CImagePro20190852View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CImagePro20190852View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CImagePro20190852View 진단

#ifdef _DEBUG
void CImagePro20190852View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CImagePro20190852View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CImagePro20190852Doc* CImagePro20190852View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImagePro20190852Doc)));
	return (CImagePro20190852Doc*)m_pDocument;
}
#endif //_DEBUG






void CImagePro20190852View::OnPixelHistoEq()
{
	CImagePro20190852Doc* pDoc = GetDocument();
	int x, y, i, k;
	int acc_hist;
	int N = pDoc->imageHeight * pDoc->imageWidth; //화소의 개수
	int hist[256], sum[256]; //그대로 유지 (밝기 값이기 때문)

	//히스토그램 구하기
	for (i = 0; i < 256; i++) hist[i] = 0;

	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++) {
			k = pDoc->inputImg[y][x];
			hist[k]++;
		}

	//누적분포 구하기: 밝기
	acc_hist = 0;
	for (i = 0; i < 256; i++) {
		acc_hist += hist[i];
		sum[i] = acc_hist;
	}

	//평활화 화소값 저장 -   변경 필요
	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++) {
			if (pDoc->depth == 1) {
				k = pDoc->inputImg[y][x];
				pDoc->resultImg[y][x] = (float)sum[k] / N * 255;
			} //N or sum[k] 둘 중 하나 float 형태로 만들기 
			else {
				k = pDoc->inputImg[y][3 * x + 0];
				pDoc->resultImg[y][3 * x + 0] = (float)sum[k] / N * 255;

				k = pDoc->inputImg[y][3 * x + 1];
				pDoc->resultImg[y][3 * x + 1] = (float)sum[k] / N * 255;

				k = pDoc->inputImg[y][3 * x + 2];
				pDoc->resultImg[y][3 * x + 2] = (float)sum[k] / N * 255;
			}
		}
	Invalidate();
}
void CImagePro20190852View::OnPixelAdd() {
	CImagePro20190852Doc* pDoc = GetDocument();

	if (pDoc->inputImg == NULL) return;

	int x, y, value;

	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++) {
			if (pDoc->depth == 1) {
				value = pDoc->inputImg[y][x] + 50;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->resultImg[y][x] = value;
			}
			else {
				value = pDoc->inputImg[y][3 * x + 0] + 50;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->resultImg[y][3 * x + 0] = value;
				value = pDoc->inputImg[y][3 * x + 1] + 50;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->resultImg[y][3 * x + 1] = value;
				value = pDoc->inputImg[y][3 * x + 2] + 50;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->resultImg[y][3 * x + 2] = value;
			}
		}
	Invalidate();
}

void CImagePro20190852View::OnPixelGob()
{
	CImagePro20190852Doc* pDoc = GetDocument();
	if (pDoc->inputImg == NULL) return;

	int x, y, value;

	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++) {
			if (pDoc->depth == 1) {
							value = pDoc->inputImg[y][x] * 1.5;
			if (value > 255)
				value = 255;
			else if (value < 0)
				value = 0;
			pDoc->resultImg[y][x] = value;
			}
			else {
				value = pDoc->inputImg[y][3 * x + 0] * 1.5;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->resultImg[y][3 * x + 0] = value;
				value = pDoc->inputImg[y][3 * x + 1] * 1.5;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->resultImg[y][3 * x + 1] = value;
				value = pDoc->inputImg[y][3 * x + 2] * 1.5;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->resultImg[y][3 * x + 2] = value;
			}
		}
	Invalidate();
}
void CImagePro20190852View::OnPixelSub() {
	CImagePro20190852Doc* pDoc = GetDocument();
	if (pDoc->inputImg == NULL) return;
	int x, y, value;

	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++) {
			if (pDoc->depth == 1) {
				value = pDoc->inputImg[y][x] - 50;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->resultImg[y][x] = value;
			}
			else {
				value = pDoc->inputImg[y][3 * x + 0] - 50;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->resultImg[y][3 * x + 0] = value;
				value = pDoc->inputImg[y][3 * x + 1] - 50;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->resultImg[y][3 * x + 1] = value;
				value = pDoc->inputImg[y][3 * x + 2] - 50;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->resultImg[y][3 * x + 2] = value;
			}
		}
	Invalidate();
}


void CImagePro20190852View::OnPixelDiv()
{
	CImagePro20190852Doc* pDoc = GetDocument();
	if (pDoc->inputImg == NULL) return;
	int x, y, value;

	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++) {
			if (pDoc->depth ==1)
			{
				value = pDoc->inputImg[y][x] / 1.5;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->resultImg[y][x] = value;
			}
			else 
			{
				value = pDoc->inputImg[y][3 * x + 0] / 1.5;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->resultImg[y][3 * x + 0] = value;
				value = pDoc->inputImg[y][3 * x + 1] / 1.5;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->resultImg[y][3 * x + 1] = value;
				value = pDoc->inputImg[y][3 * x + 2] /1.5;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->resultImg[y][3 * x + 2] = value;
			}
	}
	Invalidate();
}


void CImagePro20190852View::OnPixelContrastStretch()
{
	CImagePro20190852Doc* pDoc = GetDocument();
	int x, y, value;
	int min = 255, max = 0;

	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++) {
			if (pDoc->depth == 1) {
				if (pDoc->inputImg[y][x] < min) min = pDoc->inputImg[y][x];
				if (pDoc->inputImg[y][x] > max) max = pDoc->inputImg[y][x];
			}
			else {
				if (pDoc->inputImg[y][3 * x + 0] < min) min = pDoc->inputImg[y][3 * x + 0];
				if (pDoc->inputImg[y][3 * x + 0] > max) max = pDoc->inputImg[y][3 * x + 0];

				if (pDoc->inputImg[y][3 * x + 1] < min) min = pDoc->inputImg[y][3 * x + 1];
				if (pDoc->inputImg[y][3 * x + 1] > max) max = pDoc->inputImg[y][3 * x + 1];

				if (pDoc->inputImg[y][3 * x + 2] < min) min = pDoc->inputImg[y][3 * x + 2];
				if (pDoc->inputImg[y][3 * x + 2] > max) max = pDoc->inputImg[y][3 * x + 2];
			}
		}

	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++) {
			if (pDoc->depth == 1) {
				value = pDoc->inputImg[y][x];
				pDoc->resultImg[y][x] = (float)(value - min) / (max - min) * 255;
			}
			else {
				value = pDoc->inputImg[y][3 * x + 0];
				pDoc->resultImg[y][3 * x + 0] = (float)(value - min) / (max - min) * 255;

				value = pDoc->inputImg[y][3 * x + 1];
				pDoc->resultImg[y][3 * x + 1] = (float)(value - min) / (max - min) * 255;

				value = pDoc->inputImg[y][3 * x + 2];
				pDoc->resultImg[y][3 * x + 2] = (float)(value - min) / (max - min) * 255;
			}
		}

	Invalidate();
}



void CImagePro20190852View::OnPixelBinarization() //이진화
{
	CImagePro20190852Doc* pDoc = GetDocument();
	int x, y, value;
	int threshold = 150;

	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++) {
			if (pDoc->depth == 1) {
				value = pDoc->inputImg[y][x];
				if (value >= threshold)
					pDoc->resultImg[y][x] = 255;
				else
					pDoc->resultImg[y][x] = 0;
			}
			else {
				value = pDoc->inputImg[y][3 * x + 0];
				if (value >= threshold)
					pDoc->resultImg[y][3 * x + 0] = 255;
				else
					pDoc->resultImg[y][3 * x + 0] = 0;

				value = pDoc->inputImg[y][3 * x + 1];
				if (value >= threshold)
					pDoc->resultImg[y][3 * x + 1] = 255;
				else
					pDoc->resultImg[y][3 * x + 1] = 0;

				value = pDoc->inputImg[y][3 * x + 2];
				if (value >= threshold)
					pDoc->resultImg[y][3 * x + 2] = 255;
				else
					pDoc->resultImg[y][3 * x + 2] = 0;
			}
		}
	Invalidate();
}


void CImagePro20190852View::OnPixelTwoImagegAdd()
{
	CImagePro20190852Doc* pDoc = GetDocument();
	
	CFileDialog dlg(TRUE);

	if (dlg.DoModal() != IDOK)
	{
		return;
	}
	CFile file;
	file.Open(dlg.GetPathName(), CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	pDoc->LoadSeondimage(ar);
	file.Close();
	//LoadTwoimage();
	int x, y, value;
	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++)
		{
			value = 0.3*pDoc->inputImg[y][x] + 0.7*pDoc->inputImg2[y][x];
			if (value > 255) value = 255;
			else if (value < 0) value = 0;
			pDoc->resultImg[y][x] = value;
		}
	Invalidate();
}


void CImagePro20190852View::LoadTwoimage()
{
	CImagePro20190852Doc* pDoc = GetDocument();
	CFileDialog dlg(TRUE);
	if (dlg.DoModal() == IDOK)
	{
		CFile file;
		file.Open(dlg.GetPathName(), CFile::modeRead);
		file.Read(pDoc->inputImg2, 256 * 256);
		file.Close();
	}
	Invalidate();
}


void CImagePro20190852View::OnPixelTwoImageSub()
{
	CImagePro20190852Doc* pDoc = GetDocument();

	CFileDialog dlg(TRUE);

	if (dlg.DoModal() != IDOK)
	{
		return;
	}
	CFile file;
	file.Open(dlg.GetPathName(), CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	pDoc->LoadSeondimage(ar);
	file.Close();
	//LoadTwoimage();
	int x, y, value;
	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++)
		{
			value = abs(pDoc->inputImg[y][x] - pDoc->inputImg2[y][x]);
			if (value > 64) value = 255;
			else value = 0;
			if (value > 255) value = 255;
			else if (value < 0) value = 0;
			pDoc->resultImg[y][x] = value;
		}
	Invalidate();
}


void CImagePro20190852View::OnRegionSmoothing()
{
	CImagePro20190852Doc* pDoc = GetDocument();

	float kernel[3][3] = { {1/9.0,1/9.0,1/9.0},
		                             {1/9.0,1/9.0,1/9.0},
		                             {1/9.0,1/9.0,1/9.0} };

	Convolve(pDoc->inputImg, pDoc->resultImg, pDoc->imageWidth, pDoc->imageHeight, kernel
		, 0, pDoc->depth);

	Invalidate();
}


void CImagePro20190852View::Convolve(unsigned char** inimg, unsigned char** Outimg, int cols, int rows, float mask[][3], int bias, int depth)
{
	int x, y, value, i, j;
	float sum, redsum,greensum, bluesum;
	//y= imageHeight =rows=j / x =imageWidth=cols  =i
	for (y = 1; y < rows-1; y++)
		for (x = 1; x < cols-1; x++) 
		{
			if (depth == 1)
			{
				sum = 0;
				for (j = 0; j < 3; j++)
					for (i = 0; i < 3; i++)
					{
						sum += inimg[y - 1 + j][x - 1 + i] * mask[j][i];
					}
				sum += bias;
				if (sum > 255) sum = 255;
				else if (sum < 0) sum = 0;
				Outimg[y][x] = sum;
			}
			else
			{
				redsum = 0; greensum = 0; bluesum = 0;
				for (j = 0; j < 3; j++)
					for (i = 0; i < 3; i++)
					{
						redsum += inimg[y - 1 + j][3*(x - 1 + i)+0] * mask[j][i];
						greensum += inimg[y - 1 + j][3 * (x - 1 + i) + 1] * mask[j][i];
						bluesum += inimg[y - 1 + j][3 * (x - 1 + i) + 2] * mask[j][i];
					}
				redsum += bias;
				greensum += bias;
				bluesum += bias;

				if (redsum > 255) redsum = 255;
				else if (redsum < 0) redsum = 0;
				if (greensum > 255) greensum = 255;
				else if (greensum < 0) greensum = 0;
				if (bluesum > 255) bluesum = 255;
				else if (bluesum < 0) bluesum = 0;

				Outimg[y][3 * x + 0] = redsum;
				Outimg[y][3 * x + 1] = greensum;
				Outimg[y][3 * x + 2] = bluesum;
			}
		}
}


void CImagePro20190852View::OnRegionSharpening()
{
	CImagePro20190852Doc* pDoc = GetDocument();

	float kernel[3][3] = { {0,-1,0},
									 {-1,5,-1},
									 {0,-1,0} };

	Convolve(pDoc->inputImg, pDoc->resultImg, pDoc->imageWidth, pDoc->imageHeight, kernel
		, 0, pDoc->depth);

	Invalidate();
}


void CImagePro20190852View::OnRegionEmbosing()
{
	CImagePro20190852Doc* pDoc = GetDocument();

	float kernel[3][3] = { {-1,0,0},
									 {0,0,0},
									 {0,0,1} };

	Convolve(pDoc->inputImg, pDoc->resultImg, pDoc->imageWidth, pDoc->imageHeight, kernel
		, 128, pDoc->depth);

	Invalidate();
}


void CImagePro20190852View::OnRegionPrewitt()

{
	CImagePro20190852Doc* pDoc = GetDocument();
	float Hmask[3][3] = { {-1,-1,-1},
								      {0,0,0},
								      {1,1,1} };
	float Vmask[3][3] = { {-1,0,1},
								      {-1,0,1},
								      {-1,0,1} };

	unsigned char** Er, ** Ec;
	int x, y, value;

	Er = (unsigned char**)malloc(pDoc->imageHeight * sizeof(unsigned char*));
	Ec = (unsigned char**)malloc(pDoc->imageHeight * sizeof(unsigned char*));

	for (int i = 0; i < pDoc->imageHeight; i++) {
		Er[i] = (unsigned char*)malloc(pDoc->imageWidth * pDoc->depth);
		Ec[i] = (unsigned char*)malloc(pDoc->imageWidth * pDoc->depth);
	}

	Convolve(pDoc->inputImg, Er, pDoc->imageWidth, pDoc->imageHeight, Hmask
		, 0, pDoc->depth);
	Convolve(pDoc->inputImg, Ec, pDoc->imageWidth, pDoc->imageHeight, Vmask
		, 0, pDoc->depth);

	for( y=0; y<pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++)
		{
			if (pDoc->depth == 1) {
				value = sqrt(Er[y][x] * Er[y][x] + Ec[y][x]*Ec[y][x]);
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImg[y][x] = value;
			}
			else {
				value = sqrt(Er[y][3*x+0] * Er[y][3 * x + 0] + Ec[y][3 * x + 0]*Ec[y][3 * x + 0]);
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImg[y][3 * x + 0] = value;

				value = sqrt(Er[y][3 * x + 1] * Er[y][3 * x + 1] + Ec[y][3 * x + 1] * Ec[y][3 * x + 1]);
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImg[y][3 * x + 1] = value;

				value = sqrt(Er[y][3 * x + 2] * Er[y][3 * x + 2] + Ec[y][3 * x + 2] * Ec[y][3 * x + 2]);
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImg[y][3 * x + 2] = value;


				value = sqrt(pDoc->resultImg[y][3 * x + 0] * pDoc->resultImg[y][3 * x + 0] +
					pDoc->resultImg[y][3 * x + 1] * pDoc->resultImg[y][3 * x + 1] +
					pDoc->resultImg[y][3 * x + 2] * pDoc->resultImg[y][3 * x + 2]);
				if (value > 255) value = 255;
				else if (value < 0) value = 0;

				pDoc->resultImg[y][3 * x + 0] = value;
				pDoc->resultImg[y][3 * x + 1] = value;
				pDoc->resultImg[y][3 * x + 2] = value;
			}
		}
	// 메모리 해제
	for (int i = 0; i < pDoc->imageHeight; i++)
	{
		free(Er[i]);
		free(Ec[i]);
	}
	free(Er);
	free(Ec);

	Invalidate();
}


void CImagePro20190852View::OnRegionRoberts()
{
	CImagePro20190852Doc* pDoc = GetDocument();
	float Hmask[3][3] = { {-1,0,0},
									  {0,-1,0},
									  {0,0,0} };
	float Vmask[3][3] = { {0,0,-1},
									  {0,1,0},
									  {0,0,0} };

	unsigned char** Er, ** Ec;
	int x, y, value;

	Er = (unsigned char**)malloc(pDoc->imageHeight * sizeof(unsigned char*));
	Ec = (unsigned char**)malloc(pDoc->imageHeight * sizeof(unsigned char*));

	for (int i = 0; i < pDoc->imageHeight; i++) {
		Er[i] = (unsigned char*)malloc(pDoc->imageWidth * pDoc->depth);
		Ec[i] = (unsigned char*)malloc(pDoc->imageWidth * pDoc->depth);
	}

	Convolve(pDoc->inputImg, Er, pDoc->imageWidth, pDoc->imageHeight, Hmask
		, 0, pDoc->depth);
	Convolve(pDoc->inputImg, Ec, pDoc->imageWidth, pDoc->imageHeight, Vmask
		, 0, pDoc->depth);

	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++)
		{
			if (pDoc->depth == 1) {
				value = sqrt(Er[y][x] * Er[y][x] + Ec[y][x]);
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImg[y][x] = value;
			}
			else {
				value = sqrt(Er[y][3 * x + 0] * Er[y][3 * x + 0] + Ec[y][3 * x + 0] * Ec[y][3 * x + 0]);
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImg[y][3 * x + 0] = value;

				value = sqrt(Er[y][3 * x + 1] * Er[y][3 * x + 1] + Ec[y][3 * x + 1] * Ec[y][3 * x + 1]);
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImg[y][3 * x + 1] = value;

				value = sqrt(Er[y][3 * x + 2] * Er[y][3 * x + 2] + Ec[y][3 * x + 2] * Ec[y][3 * x + 2]);
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImg[y][3 * x + 2] = value;


				value = sqrt(pDoc->resultImg[y][3 * x + 0] * pDoc->resultImg[y][3 * x + 0] +
					pDoc->resultImg[y][3 * x + 1] * pDoc->resultImg[y][3 * x + 1] +
					pDoc->resultImg[y][3 * x + 2] * pDoc->resultImg[y][3 * x + 2]);
				if (value > 255) value = 255;
				else if (value < 0) value = 0;

				pDoc->resultImg[y][3 * x + 0] = value;
				pDoc->resultImg[y][3 * x + 1] = value;
				pDoc->resultImg[y][3 * x + 2] = value;
			}
		}
	// 메모리 해제
	for (int i = 0; i < pDoc->imageHeight; i++)
	{
		free(Er[i]);
		free(Ec[i]);
	}
	free(Er);
	free(Ec);

	Invalidate();
}


void CImagePro20190852View::OnRegionSobel()
{
	CImagePro20190852Doc* pDoc = GetDocument();
	float Hmask[3][3] = { {-1,-2,-1},
									  {0,0,0},
									  {1,2,1} };
	float Vmask[3][3] = { {-1,0,1},
									  {-2,0,2},
									  {-1,0,1} };

	unsigned char** Er, ** Ec;
	int x, y, value;

	Er = (unsigned char**)malloc(pDoc->imageHeight * sizeof(unsigned char*));
	Ec = (unsigned char**)malloc(pDoc->imageHeight * sizeof(unsigned char*));

	for (int i = 0; i < pDoc->imageHeight; i++) {
		Er[i] = (unsigned char*)malloc(pDoc->imageWidth * pDoc->depth);
		Ec[i] = (unsigned char*)malloc(pDoc->imageWidth * pDoc->depth);
	}

	Convolve(pDoc->inputImg, Er, pDoc->imageWidth, pDoc->imageHeight, Hmask
		, 0, pDoc->depth);
	Convolve(pDoc->inputImg, Ec, pDoc->imageWidth, pDoc->imageHeight, Vmask
		, 0, pDoc->depth);

	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++)
		{
			if (pDoc->depth == 1) {
				value = sqrt(Er[y][x] * Er[y][x] + Ec[y][x]);
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImg[y][x] = value;
			}
			else {
				value = sqrt(Er[y][3 * x + 0] * Er[y][3 * x + 0] + Ec[y][3 * x + 0] * Ec[y][3 * x + 0]);
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImg[y][3 * x + 0] = value;

				value = sqrt(Er[y][3 * x + 1] * Er[y][3 * x + 1] + Ec[y][3 * x + 1] * Ec[y][3 * x + 1]);
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImg[y][3 * x + 1] = value;

				value = sqrt(Er[y][3 * x + 2] * Er[y][3 * x + 2] + Ec[y][3 * x + 2] * Ec[y][3 * x + 2]);
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->resultImg[y][3 * x + 2] = value;

				value = sqrt(pDoc->resultImg[y][3 * x + 0] * pDoc->resultImg[y][3 * x + 0] +
					pDoc->resultImg[y][3 * x + 1] * pDoc->resultImg[y][3 * x + 1] +
					pDoc->resultImg[y][3 * x + 2] * pDoc->resultImg[y][3 * x + 2]);
				if (value > 255) value = 255;
				else if (value < 0) value = 0;

				pDoc->resultImg[y][3 * x + 0] = value;
				pDoc->resultImg[y][3 * x + 1] = value;
				pDoc->resultImg[y][3 * x + 2] = value;
			}
		}
	// 메모리 해제
	for (int i = 0; i < pDoc->imageHeight; i++)
	{
		free(Er[i]);
		free(Ec[i]);
	}
	free(Er);
	free(Ec);

	Invalidate();
}


void CImagePro20190852View::OnRegionAverageFiltering()
{
	CImagePro20190852Doc* pDoc = GetDocument();
	int i,x, y,j;
	int xcor, ycor;
	int sum, count, rsum,gsum,bsum;

	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++)
		{
			if (pDoc->depth == 1)
			{
				sum = 0;
				count = 0;
				for (j = -2; j <= 2; j++)
					for (i = -2; i <= 2; i++)
					{
						ycor = y + j;
						xcor = x + j;

						if (0 <= ycor && ycor <= pDoc->imageHeight - 1 && 0 <= xcor && xcor <= pDoc->imageWidth - 1)
						{
							sum += pDoc->inputImg[ycor][xcor];
							count++;
						}
					}
				pDoc->resultImg[y][x] = sum / count;
			}
			else {
				rsum = gsum = bsum = 0;
				count = 0;
				for (j = -2; j <= 2; j++)
					for (i = -2; i <= 2; i++)
					{
						ycor = y + j;
						xcor = x + j;

						if (0 <= ycor && ycor <= pDoc->imageHeight - 1 && 0 <= xcor && xcor <= pDoc->imageWidth - 1)
						{
							rsum += pDoc->inputImg[ycor][3 * xcor + 0];
							gsum += pDoc->inputImg[ycor][3 * xcor + 1];
							bsum += pDoc->inputImg[ycor][3 * xcor + 2];
							count++;
						}
					}
				pDoc->resultImg[y][3 * x + 0] = rsum / count;
				pDoc->resultImg[y][3 * x + 1] = gsum / count;
				pDoc->resultImg[y][3 * x + 2] = bsum / count;
			}
		}
	Invalidate();
}


void CImagePro20190852View::OnRegionMedianFiltering()
{
	CImagePro20190852Doc* pDoc = GetDocument();
	int x,  y, i, j;
	int n[9], temp;

	for (y = 1; y < pDoc->imageHeight-1; y++)
		for (x = 1; x < pDoc->imageWidth - 1; x++)
		{
			if (pDoc->depth == 1)
			{
				n[0] = pDoc->inputImg[y - 1][x - 1];
				n[1] = pDoc->inputImg[y - 1][x - 0];
				n[2] = pDoc->inputImg[y - 1][x + 1];
				n[3] = pDoc->inputImg[y - 0][x - 1];
				n[4] = pDoc->inputImg[y - 0][x - 0];
				n[5] = pDoc->inputImg[y - 0][x + 1];
				n[6] = pDoc->inputImg[y + 1][x - 1];
				n[7] = pDoc->inputImg[y + 1][x - 0];
				n[8] = pDoc->inputImg[y + 1][x + 1];

				//sorting
				for (i = 8; i > 0; i--)
					for (j = 0; j < i; j++)
						if (n[j] > n[j + 1]) //앞에가 크고 뒤에가 작아 두개를 교환
						{
							temp = n[j + 1];
							n[j + 1] = n[j];
							n[j] = temp;
						}
				pDoc->resultImg[y][x] = n[4];
			}
			else 
			{
				n[0] = pDoc->inputImg[y - 1][3*(x - 1)+0];
				n[1] = pDoc->inputImg[y - 1][3 * (x - 0) + 0];
				n[2] = pDoc->inputImg[y - 1][3 * (x + 1) + 0];
				n[3] = pDoc->inputImg[y - 0][3 * (x - 1) + 0];
				n[4] = pDoc->inputImg[y - 0][3 * (x - 0) + 0];
				n[5] = pDoc->inputImg[y - 0][3 * (x + 1) + 0];
				n[6] = pDoc->inputImg[y + 1][3 * (x - 1) + 0];
				n[7] = pDoc->inputImg[y + 1][3 * (x - 0) + 0];
				n[8] = pDoc->inputImg[y + 1][3 * (x + 1) + 0];

				//sorting
				for (i = 8; i > 0; i--)
					for (j = 0; j < i; j++)
						if (n[j] > n[j + 1]) //앞에가 크고 뒤에가 작아 두개를 교환
						{
							temp = n[j + 1];
							n[j + 1] = n[j];
							n[j] = temp;
						}
				pDoc->resultImg[y][3*x+0] = n[4];

				n[0] = pDoc->inputImg[y - 1][3 * (x - 1) + 1];
				n[1] = pDoc->inputImg[y - 1][3 * (x - 0) + 1];
				n[2] = pDoc->inputImg[y - 1][3 * (x + 1) + 1];
				n[3] = pDoc->inputImg[y - 0][3 * (x - 1) + 1];
				n[4] = pDoc->inputImg[y - 0][3 * (x - 0) + 1];
				n[5] = pDoc->inputImg[y - 0][3 * (x + 1) + 1];
				n[6] = pDoc->inputImg[y + 1][3 * (x - 1) + 1];
				n[7] = pDoc->inputImg[y + 1][3 * (x - 0) + 1];
				n[8] = pDoc->inputImg[y + 1][3 * (x + 1) + 1];

				//sorting
				for (i = 8; i > 0; i--)
					for (j = 0; j < i; j++)
						if (n[j] > n[j + 1]) 
						{
							temp = n[j + 1];
							n[j + 1] = n[j];
							n[j] = temp;
						}
				pDoc->resultImg[y][3 * x + 1] = n[4];

				n[0] = pDoc->inputImg[y - 1][3 * (x - 1) + 2];
				n[1] = pDoc->inputImg[y - 1][3 * (x - 0) + 2];
				n[2] = pDoc->inputImg[y - 1][3 * (x + 1) + 2];
				n[3] = pDoc->inputImg[y - 0][3 * (x - 1) + 2];
				n[4] = pDoc->inputImg[y - 0][3 * (x - 0) + 2];
				n[5] = pDoc->inputImg[y - 0][3 * (x + 1) + 2];
				n[6] = pDoc->inputImg[y + 1][3 * (x - 1) + 2];
				n[7] = pDoc->inputImg[y + 1][3 * (x - 0) + 2];
				n[8] = pDoc->inputImg[y + 1][3 * (x + 1) + 2];

				//sorting
				for (i = 8; i > 0; i--)
					for (j = 0; j < i; j++)
						if (n[j] > n[j + 1]) 
						{
							temp = n[j + 1];
							n[j + 1] = n[j];
							n[j] = temp;
						}
				pDoc->resultImg[y][3 * x + 2] = n[4];
			}
		}
	Invalidate();
}


void CImagePro20190852View::OnMopologyColorGray()
{
	CImagePro20190852Doc* pDoc = GetDocument();
	int x, y, gray;

	if (pDoc->depth == 1) return;

	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++)
		{
			gray = (pDoc->inputImg[y][3 * x + 0] + pDoc->inputImg[y][3 * x + 1] +
				pDoc->inputImg[y][3 * x + 2]) / 3;
			pDoc->inputImg[y][3 * x + 0] = gray;
			pDoc->inputImg[y][3 * x + 1] = gray;
			pDoc->inputImg[y][3 * x + 2] = gray;
		}
	Invalidate();
}


void CImagePro20190852View::OnMopologyBinarization()
{
	CImagePro20190852Doc* pDoc = GetDocument();

	int x, y;
	int thresh = 128;

	for (y = 0; y < pDoc->imageHeight - 1; y++)
		for (x = 0; x < pDoc->imageWidth - 1; x++) {
			if (pDoc->depth == 1) {
				if (pDoc->inputImg[y][x] > thresh)
					pDoc->inputImg[y][x] = 255;
				else
					pDoc->inputImg[y][x] = 0;
			}
			else {
				if ((pDoc->inputImg[y][3 * x + 0]
					+ pDoc->inputImg[y][3 * x + 1]
					+ pDoc->inputImg[y][3 * x + 2]) / 3
	> thresh) {
					pDoc->inputImg[y][3 * x + 0] = 255;
					pDoc->inputImg[y][3 * x + 1] = 255;
					pDoc->inputImg[y][3 * x + 2] = 255;
				}
				else {
					pDoc->inputImg[y][3 * x + 0] = 0;
					pDoc->inputImg[y][3 * x + 1] = 0;
					pDoc->inputImg[y][3 * x + 2] = 0;
				}
			}
		}
	Invalidate();

}


void CImagePro20190852View::OnMopologyErosion()
{
	CImagePro20190852Doc* pDoc = GetDocument();

	int x, y,j;
	int min, rmin, gmin, bmin = 255;


	for (y = 1; y < pDoc->imageHeight-1; y++)
		for (x = 1; x < pDoc->imageWidth-1; x++)
		{
			if (pDoc->depth == 1)
			{
				min = 255;
				for (j = -1; j <= 1; j++)
					for (int i = -1; i <= 1; i++)
					{
						if (pDoc->inputImg[y + j][x + i] < min)
							min = pDoc->inputImg[y + j][x + i];
					}
				pDoc->resultImg[y][x] = min;
			}
			else
			{
				rmin = 255; gmin = 255; bmin = 255;
				for (j = -1; j <= 1; j++)
					for (int i = -1; i <= 1; i++)
					{
						if (pDoc->inputImg[y + j][3*(x + i)+0] < rmin)
							rmin = pDoc->inputImg[y + j][3*(x + i)+0];
						if (pDoc->inputImg[y + j][3 * (x + i) + 1] < gmin)
							gmin = pDoc->inputImg[y + j][3 * (x + i) + 1];
						if (pDoc->inputImg[y + j][3 * (x + i) + 2] < bmin)
							bmin = pDoc->inputImg[y + j][3 * (x + i) + 2];
					}
				pDoc->resultImg[y][3 * x + 0] = rmin;
				pDoc->resultImg[y][3 * x + 1] = gmin;
				pDoc->resultImg[y][3 * x + 2] = bmin;
			}
		}
	Invalidate();
}

void CImagePro20190852View::OnMopologyDilation()
{
	CImagePro20190852Doc* pDoc = GetDocument();

	int x, y, j;
	int max, rmax, gmax, bmax = 0;


	for (y = 1; y < pDoc->imageHeight - 1; y++)
		for (x = 1; x < pDoc->imageWidth - 1; x++)
		{
			if (pDoc->depth == 1)
			{
				max = 0;
				for (j = -1; j <= 1; j++)
					for (int i = -1; i <= 1; i++)
					{
						if (pDoc->inputImg[y + j][x + i] > max)
							max = pDoc->inputImg[y + j][x + i];
					}
				pDoc->resultImg[y][x] = max;
			}
			else
			{
				rmax = 0; gmax = 0; bmax = 0;
				for (j = -1; j <= 1; j++)
					for (int i = -1; i <= 1; i++)
					{
						if (pDoc->inputImg[y + j][3 * (x + i) + 0] > rmax)
							rmax = pDoc->inputImg[y + j][3 * (x + i) + 0];
						if (pDoc->inputImg[y + j][3 * (x + i) + 1] > gmax)
							gmax = pDoc->inputImg[y + j][3 * (x + i) + 1];
						if (pDoc->inputImg[y + j][3 * (x + i) + 2] > bmax)
							bmax = pDoc->inputImg[y + j][3 * (x + i) + 2];
					}
				pDoc->resultImg[y][3 * x + 0] = rmax;
				pDoc->resultImg[y][3 * x + 1] = gmax;
				pDoc->resultImg[y][3 * x + 2] = bmax;
			}
		}
	Invalidate();
}

void CImagePro20190852View::OnMopologyOpening()
{
	OnMopologyErosion();
	CopyResultToInput();
	OnMopologyErosion();
	CopyResultToInput();
	OnMopologyErosion();

	CopyResultToInput();
	OnMopologyDilation();
	CopyResultToInput();
	OnMopologyDilation();
	CopyResultToInput();
	OnMopologyDilation();
}


void CImagePro20190852View::CopyResultToInput()
{
	CImagePro20190852Doc* pDoc = GetDocument();

	int x, y;
	for (y = 0; y < pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth*pDoc->depth; x++)
		{
			pDoc->inputImg[y][x] = pDoc->resultImg[y][x];
		}
}


void CImagePro20190852View::OnMopologyColsing()
{
	OnMopologyDilation();
	CopyResultToInput();
	OnMopologyDilation();
	CopyResultToInput();
	OnMopologyDilation();

    CopyResultToInput();
	
	OnMopologyErosion();
	CopyResultToInput();
	OnMopologyErosion();
	CopyResultToInput();
	OnMopologyErosion();

	
	
}


void CImagePro20190852View::OnGeometryZoominPixelCopy()
{
	CImagePro20190852Doc* pDoc = GetDocument();

	int x, y;
	int xscale = 3;
	int yscale = 2;

	if (pDoc->gresultImg != NULL)
	{
		for (int i = 0; i < pDoc->gimageHeight; i++)
			free(pDoc->gresultImg[i]);
		free(pDoc->gresultImg);
	}

	pDoc->gimageWidth = pDoc->imageWidth * xscale;
	pDoc->gimageHeight = pDoc->imageHeight * yscale;
	// 메모리할당
	pDoc->gresultImg = (unsigned char**)malloc(pDoc->gimageHeight * sizeof(unsigned char*));
	for (int i = 0; i < pDoc->gimageHeight; i++)
	{
		pDoc->gresultImg[i] = (unsigned char*)malloc(pDoc->gimageWidth * pDoc->depth);
	}
	//역방향 사상
	for (y = 0; y < pDoc->gimageHeight; y++)
		for (x = 0; x < pDoc->gimageWidth; x++)
		{
			if (pDoc->depth == 1)
				pDoc->gresultImg[y][x] = pDoc->inputImg[y / yscale][x / xscale];
			else
			{
				pDoc->gresultImg[y][3 * x + 0] = pDoc->inputImg[y / yscale][3 * (x / xscale) + 0];
				pDoc->gresultImg[y][3 * x + 1] = pDoc->inputImg[y / yscale][3 * (x / xscale) + 1];
				pDoc->gresultImg[y][3 * x + 2] = pDoc->inputImg[y / yscale][3 * (x / xscale) + 2];
			}
		}
	/* 전방향 사상
	for(y=0; y<pDoc->imageHeight; y++)
		for (x = 0; x < pDoc->imageWidth; x++)
		{
		pDoc->gresultImg[y][x] = pDoc->inputImg[y/yscale][x/xscale];
		}
	*/

	Invalidate();
}


void CImagePro20190852View::OnGeometryZoominBinarInterpolation()
{
	CImagePro20190852Doc* pDoc = GetDocument();

	int x, y;

	float xscale = 2.3;
	float yscale = 1.5;
	float src_x, src_y;
	float alpha, beta;
	int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
	int E, F;

	// 메모리 제거
	if (pDoc->gresultImg != NULL)
	{
		for (int i = 0; i < pDoc->gimageHeight; i++)
			free(pDoc->gresultImg[i]);
		free(pDoc->gresultImg);
	}

	pDoc->gimageWidth = pDoc->imageWidth * xscale + 0.5;
	pDoc->gimageHeight = pDoc->imageHeight * yscale + 0.5;

	// 메모리 할당
	pDoc->gresultImg = (unsigned char**)malloc(pDoc->gimageHeight * sizeof(unsigned char*));
	for (int i = 0; i < pDoc->gimageHeight; i++) {

		pDoc->gresultImg[i] = (unsigned char*)malloc(pDoc->gimageWidth * pDoc->depth);
	}
	//역방향 사상
	for (y = 0; y < pDoc->gimageHeight; y++)
		for (x = 0; x < pDoc->gimageWidth; x++)
		{
			src_x = x / xscale;
			src_y = y / yscale;
			alpha = src_x - (int)src_x;
			beta = src_y - (int)src_y;

			Ax = (int)src_x;
			Ay = (int)src_y;

			Bx = Ax + 1;
			By = Ay;

			Cx = Ax;
			Cy = Ay + 1;

			Dx = Ax + 1;
			Dy = Ay + 1;

			if (Bx > pDoc->imageWidth - 1) Bx = pDoc->imageWidth - 1;
			if (Cy > pDoc->imageHeight - 1) Cy = pDoc->imageHeight - 1;
			if (Dx > pDoc->imageWidth - 1) Dx = pDoc->imageWidth - 1;
			if (Dy > pDoc->imageHeight - 1) Dy = pDoc->imageHeight - 1;


			if (pDoc->depth == 1) {
				E = (1 - alpha) * pDoc->inputImg[Ay][Ax] + alpha * pDoc->inputImg[By][Bx];
				F = (1 - alpha) * pDoc->inputImg[Cy][Cx] + alpha * pDoc->inputImg[Dy][Dx];
				pDoc->gresultImg[y][x] = (1 - beta) * E + beta * F;
			}
			else {
				E = (1 - alpha) * pDoc->inputImg[Ay][3 * Ax + 0] + alpha * pDoc->inputImg[By][3 * Bx + 0];
				F = (1 - alpha) * pDoc->inputImg[Cy][3 * Cx + 0] + alpha * pDoc->inputImg[Dy][3 * Dx + 0];
				pDoc->gresultImg[y][3 * x + 0] = (1 - beta) * E + beta * F;

				E = (1 - alpha) * pDoc->inputImg[Ay][3 * Ax + 1] + alpha * pDoc->inputImg[By][3 * Bx + 1];
				F = (1 - alpha) * pDoc->inputImg[Cy][3 * Cx + 1] + alpha * pDoc->inputImg[Dy][3 * Dx + 1];
				pDoc->gresultImg[y][3 * x + 1] = (1 - beta) * E + beta * F;

				E = (1 - alpha) * pDoc->inputImg[Ay][3 * Ax + 2] + alpha * pDoc->inputImg[By][3 * Bx + 2];
				F = (1 - alpha) * pDoc->inputImg[Cy][3 * Cx + 2] + alpha * pDoc->inputImg[Dy][3 * Dx + 2];
				pDoc->gresultImg[y][3 * x + 2] = (1 - beta) * E + beta * F;
			}


		}

	Invalidate();
}

void CImagePro20190852View::OnGeometryZoomout()
{
	CImagePro20190852Doc* pDoc = GetDocument();

	int xscale = 3; //1/3
	int yscale = 2; //1/2
	int x, y;

	if (pDoc->gresultImg != NULL)
	{
		for (int i = 0; i < pDoc->gimageHeight; i++)
			free(pDoc->gresultImg[i]);
		free(pDoc->gresultImg);
	}

	pDoc->gimageWidth = pDoc->imageWidth / xscale;
	pDoc->gimageHeight = pDoc->imageHeight / yscale;

	pDoc->gresultImg = (unsigned char**)malloc(pDoc->gimageHeight * sizeof(unsigned char*));
	for (int i = 0; i < pDoc->gimageHeight; i++) {

		pDoc->gresultImg[i] = (unsigned char*)malloc(pDoc->gimageWidth * pDoc->depth);
	}

	for (y = 0; y < pDoc->gimageHeight; y++)
		for (x = 0; x < pDoc->gimageWidth; x++)
		{
			if(pDoc->depth==1)
			pDoc->gresultImg[y][x] = pDoc->inputImg[y * yscale][x * xscale];
			else
			{
				pDoc->gresultImg[y][3 * x + 0] = pDoc->inputImg[y * yscale][3 * (x * xscale) + 0];
				pDoc->gresultImg[y][3 * x + 1] = pDoc->inputImg[y * yscale][3 * (x * xscale) + 1];
				pDoc->gresultImg[y][3 * x + 2] = pDoc->inputImg[y * yscale][3 * (x * xscale) + 2];
			}
		}
	Invalidate();
}


void CImagePro20190852View::OnGeometryZoomoutMeanSub()
{
	OnRegionSmoothing();

	OnGeometryZoomout();

	CopyResultToInput();
}


void CImagePro20190852View::OnGeometryAvgFiltering()
{
	CImagePro20190852Doc* pDoc = GetDocument();

	int xscale = 3; // 1/3의 값
	int yscale = 2; // 1/2의 값

	int x, y, i, j;
	int sum, rsum, gsum, bsum;
	int src_x, src_y;


	if (pDoc->gresultImg != NULL)
	{
		for (int i = 0; i < pDoc->gimageHeight; i++)
			free(pDoc->gresultImg[i]);
		free(pDoc->gresultImg);
	}

	pDoc->gimageWidth = pDoc->imageWidth / xscale;
	pDoc->gimageHeight = pDoc->imageHeight / yscale;

	pDoc->gresultImg = (unsigned char**)malloc(pDoc->gimageHeight * sizeof(unsigned char*));
	for (int i = 0; i < pDoc->gimageHeight; i++) {

		pDoc->gresultImg[i] = (unsigned char*)malloc(pDoc->gimageWidth * pDoc->depth);
	}

	//전방향 사상
	for (y = 0; y < pDoc->imageHeight; y += yscale)
		for (x = 0; x < pDoc->imageWidth; x += xscale)
		{
			if (pDoc->depth == 1)
			{
				sum = 0;
				for (j = 0; j < yscale; j++)
					for (i = 0; i < xscale; i++)
					{
						src_x = x + i;
						src_y = y + j;

						sum += pDoc->inputImg[src_y][src_x];
					}
				pDoc->gresultImg[y / yscale][x / xscale] = sum / (xscale * yscale);
			}
			else {
				rsum = 0;
				gsum = 0;
				bsum = 0;

				for (j = 0; j < yscale; j++)
					for (i = 0; i < xscale; i++)
					{
						src_x = x + i;
						src_y = y + j;

						rsum += pDoc->inputImg[src_y][3 * src_x + 0];
						gsum += pDoc->inputImg[src_y][3 * src_x + 1];
						bsum += pDoc->inputImg[src_y][3 * src_x + 2];
					}
				pDoc->gresultImg[y / yscale][3 * (x / xscale) + 0] = rsum / (xscale * yscale);
				pDoc->gresultImg[y / yscale][3 * (x / xscale) + 1] = gsum / (xscale * yscale);
				pDoc->gresultImg[y / yscale][3 * (x / xscale) + 2] = bsum / (xscale * yscale);
			}
		}
	Invalidate();
}

#define PI 3.1416926521

#include "CAngleDialog.h"
void CImagePro20190852View::OnGeometryRotation()
{
	CImagePro20190852Doc* pDoc = GetDocument();
	CAngleDialog dlg;

	int angle = 30; // 회전 각도: degree 단위
	float radian; // 각도 > radian으로 변환
	int Hy;
	int Cx, Cy;
	int x, y, xdiff, ydiff; // 밖으로 나온 영역 처리
	int x_source, y_source;

	dlg.m_iAngle = angle; //default 값 30
	if (dlg.DoModal() == IDCANCEL) return;
	angle = dlg.m_iAngle;

	radian = PI / 180 * angle;

	// y좌표의 마지막 위치
	Hy = pDoc->imageHeight - 1;

	// 영상 중심점
	Cx = pDoc->imageWidth / 2;
	Cy = pDoc->imageHeight / 2;

	if (pDoc->gresultImg != NULL)
	{
		for (int i = 0; i < pDoc->gimageHeight; i++)
			free(pDoc->gresultImg[i]);
		free(pDoc->gresultImg);
	}

	pDoc->gimageWidth = pDoc->imageHeight * fabs(cos(PI / 2 - radian)) + pDoc->imageWidth * fabs(cos(radian));
	pDoc->gimageHeight = pDoc->imageHeight * fabs(cos(radian)) + pDoc->imageWidth * fabs(cos(PI / 2 - radian));

	// 메모리 할당
	pDoc->gresultImg = (unsigned char**)malloc(pDoc->gimageHeight * sizeof(unsigned char*));
	for (int i = 0; i < pDoc->gimageHeight; i++) {

		pDoc->gresultImg[i] = (unsigned char*)malloc(pDoc->gimageWidth * pDoc->depth);
	}

	xdiff = (pDoc->gimageWidth - pDoc->imageWidth) / 2;
	ydiff = (pDoc->gimageHeight - pDoc->imageHeight) / 2;

	for (y = -ydiff; y < pDoc->gimageHeight - ydiff; y++)
		for (x = -xdiff; x < pDoc->gimageWidth - xdiff; x++)
		{

			x_source = (Hy - y - Cx) * sin(radian) + (x - Cx) * cos(radian) + Cx;
			y_source = Hy - ((Hy - y - Cy) * cos(radian) - (x - Cx) * sin(radian) + Cy);

			if (pDoc->depth == 1) {
				if (x_source < 0 || x_source > pDoc->imageWidth - 1 || y_source < 0 || y_source > pDoc->imageHeight - 1)
					pDoc->gresultImg[y + ydiff][x + xdiff] = 255;
				else
					pDoc->gresultImg[y + ydiff][x + xdiff] = pDoc->inputImg[y_source][x_source];
			}
			else {
				if (x_source < 0 || x_source > pDoc->imageWidth - 1 || y_source < 0 || y_source > pDoc->imageHeight - 1)
				{
					pDoc->gresultImg[y + ydiff][3 * (x + xdiff) + 0] = 255;
					pDoc->gresultImg[y + ydiff][3 * (x + xdiff) + 1] = 255;
					pDoc->gresultImg[y + ydiff][3 * (x + xdiff) + 2] = 255;
				}
				else
				{
					pDoc->gresultImg[y + ydiff][3 * (x + xdiff) + 0] = pDoc->inputImg[y_source][3 * (x_source)+0];
					pDoc->gresultImg[y + ydiff][3 * (x + xdiff) + 1] = pDoc->inputImg[y_source][3 * (x_source)+1];
					pDoc->gresultImg[y + ydiff][3 * (x + xdiff) + 2] = pDoc->inputImg[y_source][3 * (x_source)+2];
				}

			}
			}

			Invalidate();
		}

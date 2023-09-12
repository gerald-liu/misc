setlocal
set "wd=D:\OneDrive - HKUST Connect\Learning_MFin\FINA5120\Homework\HW%1\"
cd %wd%
for %%f in (*.md) do (
    if "%%~xf" == ".md" pandoc --pdf-engine=xelatex %%f -o %%~nf.pdf
)
endlocal
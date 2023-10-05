import fitz  # PyMuPDF

def split_pdf(input_path, output_path):
    doc = fitz.open(input_path)
    new_doc = fitz.open()  # new empty PDF to store all split pages
    
    for page_number in range(doc.page_count):
        page = doc[page_number]
        clip = page.rect  # copy page rectangle
        
        # Left half
        clip.x1 /= 2  # modify to left half
        new_page = new_doc.new_page(width = clip.width, height = clip.height)  # new page with clip dimensions
        new_page.show_pdf_page(new_page.rect, doc, page_number, clip=clip)  # fill it with old page's left half
        
        # Right half
        clip.x0, clip.x1 = clip.x1, clip.x1 * 2  # modify clip to right half
        new_page = new_doc.new_page(width = clip.width, height = clip.height)  # new page with clip dimensions
        new_page.show_pdf_page(new_page.rect, doc, page_number, clip=clip)  # fill it with old page's right half
    
    new_doc.save(output_path)  # save new PDF with all split pages

# 使用方法
# split_pdf('path_to_your_A3_pdf', 'output.pdf')

split_pdf('sp0.pdf', 'sp1.pdf')
   
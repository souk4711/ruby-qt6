#include "qtextformat-rb.hpp"
#include <qtextformat.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQTextFormat;
Class rb_cQTextBlockFormat;
Class rb_cQTextCharFormat;
Class rb_cQTextImageFormat;
Class rb_cQTextTableCellFormat;
Class rb_cQTextFrameFormat;
Class rb_cQTextTableFormat;
Class rb_cQTextListFormat;
Class rb_cQTextLength;

void Init_qtextformat(Module rb_mQt6QtGui)
{
    rb_cQTextFormat =
        // RubyQt6::QtGui::QTextFormat
        define_qlass_under<QTextFormat>(rb_mQt6QtGui, "QTextFormat")
            // Constructor
            .define_constructor(Constructor<QTextFormat>())
            .define_constructor(Constructor<QTextFormat, int>(), Arg("type"))
            // Public Functions
            .define_method("background", &QTextFormat::background)
            .define_method("bool_property", &QTextFormat::boolProperty, Arg("property_id"))
            .define_method("brush_property", &QTextFormat::brushProperty, Arg("property_id"))
            .define_method("clear_background", &QTextFormat::clearBackground)
            .define_method("clear_foreground", &QTextFormat::clearForeground)
            .define_method("clear_property", &QTextFormat::clearProperty, Arg("property_id"))
            .define_method("color_property", &QTextFormat::colorProperty, Arg("property_id"))
            .define_method("double_property", &QTextFormat::doubleProperty, Arg("property_id"))
            .define_method("foreground", &QTextFormat::foreground)
            .define_method("has_property", &QTextFormat::hasProperty, Arg("property_id"))
            .define_method("int_property", &QTextFormat::intProperty, Arg("property_id"))
            .define_method("block_format?", &QTextFormat::isBlockFormat)
            .define_method("char_format?", &QTextFormat::isCharFormat)
            .define_method("empty?", &QTextFormat::isEmpty)
            .define_method("frame_format?", &QTextFormat::isFrameFormat)
            .define_method("image_format?", &QTextFormat::isImageFormat)
            .define_method("list_format?", &QTextFormat::isListFormat)
            .define_method("table_cell_format?", &QTextFormat::isTableCellFormat)
            .define_method("table_format?", &QTextFormat::isTableFormat)
            .define_method("valid?", &QTextFormat::isValid)
            .define_method("layout_direction", &QTextFormat::layoutDirection)
            .define_method("length_property", &QTextFormat::lengthProperty, Arg("property_id"))
            .define_method("length_vector_property", &QTextFormat::lengthVectorProperty, Arg("property_id"))
            .define_method("merge", &QTextFormat::merge, Arg("other"))
            .define_method("object_index", &QTextFormat::objectIndex)
            .define_method("object_type", &QTextFormat::objectType)
            .define_method("pen_property", &QTextFormat::penProperty, Arg("property_id"))
            .define_method("properties", &QTextFormat::properties)
            .define_method("property", &QTextFormat::property, Arg("property_id"))
            .define_method("property_count", &QTextFormat::propertyCount)
            .define_method("set_background", &QTextFormat::setBackground, Arg("brush"))
            .define_method("set_foreground", &QTextFormat::setForeground, Arg("brush"))
            .define_method("set_layout_direction", &QTextFormat::setLayoutDirection, Arg("direction"))
            .define_method("set_object_index", &QTextFormat::setObjectIndex, Arg("object"))
            .define_method("set_object_type", &QTextFormat::setObjectType, Arg("type"))
            .define_method<void (QTextFormat::*)(int, const QList<QTextLength> &)>("set_property", &QTextFormat::setProperty, Arg("property_id"), Arg("lengths"))
            .define_method<void (QTextFormat::*)(int, const QVariant &)>("set_property", &QTextFormat::setProperty, Arg("property_id"), Arg("value"))
            .define_method("string_property", &QTextFormat::stringProperty, Arg("property_id"))
            .define_method("to_block_format", &QTextFormat::toBlockFormat)
            .define_method("to_char_format", &QTextFormat::toCharFormat)
            .define_method("to_frame_format", &QTextFormat::toFrameFormat)
            .define_method("to_image_format", &QTextFormat::toImageFormat)
            .define_method("to_list_format", &QTextFormat::toListFormat)
            .define_method("to_table_cell_format", &QTextFormat::toTableCellFormat)
            .define_method("to_table_format", &QTextFormat::toTableFormat)
            .define_method("type", &QTextFormat::type);

    Data_Type<QTextFormat::FormatType> rb_cQTextFormatFormatType =
        // RubyQt6::QtGui::QTextFormat::FormatType
        define_qenum_under<QTextFormat::FormatType>(rb_cQTextFormat, "FormatType");
        define_qenum_value_under(rb_cQTextFormatFormatType, "InvalidFormat", QTextFormat::FormatType::InvalidFormat);
        define_qenum_value_under(rb_cQTextFormatFormatType, "BlockFormat", QTextFormat::FormatType::BlockFormat);
        define_qenum_value_under(rb_cQTextFormatFormatType, "CharFormat", QTextFormat::FormatType::CharFormat);
        define_qenum_value_under(rb_cQTextFormatFormatType, "ListFormat", QTextFormat::FormatType::ListFormat);
        define_qenum_value_under(rb_cQTextFormatFormatType, "FrameFormat", QTextFormat::FormatType::FrameFormat);
        define_qenum_value_under(rb_cQTextFormatFormatType, "UserFormat", QTextFormat::FormatType::UserFormat);

    Data_Type<QTextFormat::Property> rb_cQTextFormatProperty =
        // RubyQt6::QtGui::QTextFormat::Property
        define_qenum_under<QTextFormat::Property>(rb_cQTextFormat, "Property");
        define_qenum_value_under(rb_cQTextFormatProperty, "ObjectIndex", QTextFormat::Property::ObjectIndex);
        define_qenum_value_under(rb_cQTextFormatProperty, "CssFloat", QTextFormat::Property::CssFloat);
        define_qenum_value_under(rb_cQTextFormatProperty, "LayoutDirection", QTextFormat::Property::LayoutDirection);
        define_qenum_value_under(rb_cQTextFormatProperty, "OutlinePen", QTextFormat::Property::OutlinePen);
        define_qenum_value_under(rb_cQTextFormatProperty, "BackgroundBrush", QTextFormat::Property::BackgroundBrush);
        define_qenum_value_under(rb_cQTextFormatProperty, "ForegroundBrush", QTextFormat::Property::ForegroundBrush);
        define_qenum_value_under(rb_cQTextFormatProperty, "BackgroundImageUrl", QTextFormat::Property::BackgroundImageUrl);
        define_qenum_value_under(rb_cQTextFormatProperty, "BlockAlignment", QTextFormat::Property::BlockAlignment);
        define_qenum_value_under(rb_cQTextFormatProperty, "BlockTopMargin", QTextFormat::Property::BlockTopMargin);
        define_qenum_value_under(rb_cQTextFormatProperty, "BlockBottomMargin", QTextFormat::Property::BlockBottomMargin);
        define_qenum_value_under(rb_cQTextFormatProperty, "BlockLeftMargin", QTextFormat::Property::BlockLeftMargin);
        define_qenum_value_under(rb_cQTextFormatProperty, "BlockRightMargin", QTextFormat::Property::BlockRightMargin);
        define_qenum_value_under(rb_cQTextFormatProperty, "TextIndent", QTextFormat::Property::TextIndent);
        define_qenum_value_under(rb_cQTextFormatProperty, "TabPositions", QTextFormat::Property::TabPositions);
        define_qenum_value_under(rb_cQTextFormatProperty, "BlockIndent", QTextFormat::Property::BlockIndent);
        define_qenum_value_under(rb_cQTextFormatProperty, "LineHeight", QTextFormat::Property::LineHeight);
        define_qenum_value_under(rb_cQTextFormatProperty, "LineHeightType", QTextFormat::Property::LineHeightType);
        define_qenum_value_under(rb_cQTextFormatProperty, "BlockNonBreakableLines", QTextFormat::Property::BlockNonBreakableLines);
        define_qenum_value_under(rb_cQTextFormatProperty, "BlockTrailingHorizontalRulerWidth", QTextFormat::Property::BlockTrailingHorizontalRulerWidth);
        define_qenum_value_under(rb_cQTextFormatProperty, "HeadingLevel", QTextFormat::Property::HeadingLevel);
        define_qenum_value_under(rb_cQTextFormatProperty, "BlockQuoteLevel", QTextFormat::Property::BlockQuoteLevel);
        define_qenum_value_under(rb_cQTextFormatProperty, "BlockCodeLanguage", QTextFormat::Property::BlockCodeLanguage);
        define_qenum_value_under(rb_cQTextFormatProperty, "BlockCodeFence", QTextFormat::Property::BlockCodeFence);
        define_qenum_value_under(rb_cQTextFormatProperty, "BlockMarker", QTextFormat::Property::BlockMarker);
        define_qenum_value_under(rb_cQTextFormatProperty, "FirstFontProperty", QTextFormat::Property::FirstFontProperty);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontCapitalization", QTextFormat::Property::FontCapitalization);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontLetterSpacing", QTextFormat::Property::FontLetterSpacing);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontWordSpacing", QTextFormat::Property::FontWordSpacing);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontStyleHint", QTextFormat::Property::FontStyleHint);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontStyleStrategy", QTextFormat::Property::FontStyleStrategy);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontKerning", QTextFormat::Property::FontKerning);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontHintingPreference", QTextFormat::Property::FontHintingPreference);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontFamilies", QTextFormat::Property::FontFamilies);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontStyleName", QTextFormat::Property::FontStyleName);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontLetterSpacingType", QTextFormat::Property::FontLetterSpacingType);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontStretch", QTextFormat::Property::FontStretch);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontFamily", QTextFormat::Property::FontFamily);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontPointSize", QTextFormat::Property::FontPointSize);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontSizeAdjustment", QTextFormat::Property::FontSizeAdjustment);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontSizeIncrement", QTextFormat::Property::FontSizeIncrement);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontWeight", QTextFormat::Property::FontWeight);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontItalic", QTextFormat::Property::FontItalic);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontUnderline", QTextFormat::Property::FontUnderline);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontOverline", QTextFormat::Property::FontOverline);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontStrikeOut", QTextFormat::Property::FontStrikeOut);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontFixedPitch", QTextFormat::Property::FontFixedPitch);
        define_qenum_value_under(rb_cQTextFormatProperty, "FontPixelSize", QTextFormat::Property::FontPixelSize);
        define_qenum_value_under(rb_cQTextFormatProperty, "LastFontProperty", QTextFormat::Property::LastFontProperty);
        define_qenum_value_under(rb_cQTextFormatProperty, "TextUnderlineColor", QTextFormat::Property::TextUnderlineColor);
        define_qenum_value_under(rb_cQTextFormatProperty, "TextVerticalAlignment", QTextFormat::Property::TextVerticalAlignment);
        define_qenum_value_under(rb_cQTextFormatProperty, "TextOutline", QTextFormat::Property::TextOutline);
        define_qenum_value_under(rb_cQTextFormatProperty, "TextUnderlineStyle", QTextFormat::Property::TextUnderlineStyle);
        define_qenum_value_under(rb_cQTextFormatProperty, "TextToolTip", QTextFormat::Property::TextToolTip);
        define_qenum_value_under(rb_cQTextFormatProperty, "TextSuperScriptBaseline", QTextFormat::Property::TextSuperScriptBaseline);
        define_qenum_value_under(rb_cQTextFormatProperty, "TextSubScriptBaseline", QTextFormat::Property::TextSubScriptBaseline);
        define_qenum_value_under(rb_cQTextFormatProperty, "TextBaselineOffset", QTextFormat::Property::TextBaselineOffset);
        define_qenum_value_under(rb_cQTextFormatProperty, "IsAnchor", QTextFormat::Property::IsAnchor);
        define_qenum_value_under(rb_cQTextFormatProperty, "AnchorHref", QTextFormat::Property::AnchorHref);
        define_qenum_value_under(rb_cQTextFormatProperty, "AnchorName", QTextFormat::Property::AnchorName);
        define_qenum_value_under(rb_cQTextFormatProperty, "OldFontLetterSpacingType", QTextFormat::Property::OldFontLetterSpacingType);
        define_qenum_value_under(rb_cQTextFormatProperty, "OldFontStretch", QTextFormat::Property::OldFontStretch);
        define_qenum_value_under(rb_cQTextFormatProperty, "OldTextUnderlineColor", QTextFormat::Property::OldTextUnderlineColor);
        define_qenum_value_under(rb_cQTextFormatProperty, "OldFontFamily", QTextFormat::Property::OldFontFamily);
        define_qenum_value_under(rb_cQTextFormatProperty, "ObjectType", QTextFormat::Property::ObjectType);
        define_qenum_value_under(rb_cQTextFormatProperty, "ListStyle", QTextFormat::Property::ListStyle);
        define_qenum_value_under(rb_cQTextFormatProperty, "ListIndent", QTextFormat::Property::ListIndent);
        define_qenum_value_under(rb_cQTextFormatProperty, "ListNumberPrefix", QTextFormat::Property::ListNumberPrefix);
        define_qenum_value_under(rb_cQTextFormatProperty, "ListNumberSuffix", QTextFormat::Property::ListNumberSuffix);
        define_qenum_value_under(rb_cQTextFormatProperty, "ListStart", QTextFormat::Property::ListStart);
        define_qenum_value_under(rb_cQTextFormatProperty, "FrameBorder", QTextFormat::Property::FrameBorder);
        define_qenum_value_under(rb_cQTextFormatProperty, "FrameMargin", QTextFormat::Property::FrameMargin);
        define_qenum_value_under(rb_cQTextFormatProperty, "FramePadding", QTextFormat::Property::FramePadding);
        define_qenum_value_under(rb_cQTextFormatProperty, "FrameWidth", QTextFormat::Property::FrameWidth);
        define_qenum_value_under(rb_cQTextFormatProperty, "FrameHeight", QTextFormat::Property::FrameHeight);
        define_qenum_value_under(rb_cQTextFormatProperty, "FrameTopMargin", QTextFormat::Property::FrameTopMargin);
        define_qenum_value_under(rb_cQTextFormatProperty, "FrameBottomMargin", QTextFormat::Property::FrameBottomMargin);
        define_qenum_value_under(rb_cQTextFormatProperty, "FrameLeftMargin", QTextFormat::Property::FrameLeftMargin);
        define_qenum_value_under(rb_cQTextFormatProperty, "FrameRightMargin", QTextFormat::Property::FrameRightMargin);
        define_qenum_value_under(rb_cQTextFormatProperty, "FrameBorderBrush", QTextFormat::Property::FrameBorderBrush);
        define_qenum_value_under(rb_cQTextFormatProperty, "FrameBorderStyle", QTextFormat::Property::FrameBorderStyle);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableColumns", QTextFormat::Property::TableColumns);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableColumnWidthConstraints", QTextFormat::Property::TableColumnWidthConstraints);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableCellSpacing", QTextFormat::Property::TableCellSpacing);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableCellPadding", QTextFormat::Property::TableCellPadding);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableHeaderRowCount", QTextFormat::Property::TableHeaderRowCount);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableBorderCollapse", QTextFormat::Property::TableBorderCollapse);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableCellRowSpan", QTextFormat::Property::TableCellRowSpan);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableCellColumnSpan", QTextFormat::Property::TableCellColumnSpan);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableCellTopPadding", QTextFormat::Property::TableCellTopPadding);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableCellBottomPadding", QTextFormat::Property::TableCellBottomPadding);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableCellLeftPadding", QTextFormat::Property::TableCellLeftPadding);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableCellRightPadding", QTextFormat::Property::TableCellRightPadding);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableCellTopBorder", QTextFormat::Property::TableCellTopBorder);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableCellBottomBorder", QTextFormat::Property::TableCellBottomBorder);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableCellLeftBorder", QTextFormat::Property::TableCellLeftBorder);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableCellRightBorder", QTextFormat::Property::TableCellRightBorder);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableCellTopBorderStyle", QTextFormat::Property::TableCellTopBorderStyle);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableCellBottomBorderStyle", QTextFormat::Property::TableCellBottomBorderStyle);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableCellLeftBorderStyle", QTextFormat::Property::TableCellLeftBorderStyle);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableCellRightBorderStyle", QTextFormat::Property::TableCellRightBorderStyle);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableCellTopBorderBrush", QTextFormat::Property::TableCellTopBorderBrush);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableCellBottomBorderBrush", QTextFormat::Property::TableCellBottomBorderBrush);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableCellLeftBorderBrush", QTextFormat::Property::TableCellLeftBorderBrush);
        define_qenum_value_under(rb_cQTextFormatProperty, "TableCellRightBorderBrush", QTextFormat::Property::TableCellRightBorderBrush);
        define_qenum_value_under(rb_cQTextFormatProperty, "ImageName", QTextFormat::Property::ImageName);
        define_qenum_value_under(rb_cQTextFormatProperty, "ImageTitle", QTextFormat::Property::ImageTitle);
        define_qenum_value_under(rb_cQTextFormatProperty, "ImageAltText", QTextFormat::Property::ImageAltText);
        define_qenum_value_under(rb_cQTextFormatProperty, "ImageWidth", QTextFormat::Property::ImageWidth);
        define_qenum_value_under(rb_cQTextFormatProperty, "ImageHeight", QTextFormat::Property::ImageHeight);
        define_qenum_value_under(rb_cQTextFormatProperty, "ImageQuality", QTextFormat::Property::ImageQuality);
        define_qenum_value_under(rb_cQTextFormatProperty, "ImageMaxWidth", QTextFormat::Property::ImageMaxWidth);
        define_qenum_value_under(rb_cQTextFormatProperty, "FullWidthSelection", QTextFormat::Property::FullWidthSelection);
        define_qenum_value_under(rb_cQTextFormatProperty, "PageBreakPolicy", QTextFormat::Property::PageBreakPolicy);
        define_qenum_value_under(rb_cQTextFormatProperty, "UserProperty", QTextFormat::Property::UserProperty);

    Data_Type<QTextFormat::ObjectTypes> rb_cQTextFormatObjectTypes =
        // RubyQt6::QtGui::QTextFormat::ObjectTypes
        define_qenum_under<QTextFormat::ObjectTypes>(rb_cQTextFormat, "ObjectTypes");
        define_qenum_value_under(rb_cQTextFormatObjectTypes, "NoObject", QTextFormat::ObjectTypes::NoObject);
        define_qenum_value_under(rb_cQTextFormatObjectTypes, "ImageObject", QTextFormat::ObjectTypes::ImageObject);
        define_qenum_value_under(rb_cQTextFormatObjectTypes, "TableObject", QTextFormat::ObjectTypes::TableObject);
        define_qenum_value_under(rb_cQTextFormatObjectTypes, "TableCellObject", QTextFormat::ObjectTypes::TableCellObject);
        define_qenum_value_under(rb_cQTextFormatObjectTypes, "UserObject", QTextFormat::ObjectTypes::UserObject);

    Data_Type<QTextFormat::PageBreakFlag> rb_cQTextFormatPageBreakFlag =
        // RubyQt6::QtGui::QTextFormat::PageBreakFlag
        define_qenum_under<QTextFormat::PageBreakFlag>(rb_cQTextFormat, "PageBreakFlag");
        define_qenum_value_under(rb_cQTextFormatPageBreakFlag, "PageBreak_Auto", QTextFormat::PageBreakFlag::PageBreak_Auto);
        define_qenum_value_under(rb_cQTextFormatPageBreakFlag, "PageBreak_AlwaysBefore", QTextFormat::PageBreakFlag::PageBreak_AlwaysBefore);
        define_qenum_value_under(rb_cQTextFormatPageBreakFlag, "PageBreak_AlwaysAfter", QTextFormat::PageBreakFlag::PageBreak_AlwaysAfter);

    Data_Type<QFlags<QTextFormat::PageBreakFlag>> rb_cQTextFormatPageBreakFlags =
        // RubyQt6::QtGui::QTextFormat::PageBreakFlags
        define_qflags_under<QTextFormat::PageBreakFlag>(rb_cQTextFormat, "PageBreakFlags");

    rb_cQTextBlockFormat =
        // RubyQt6::QtGui::QTextBlockFormat
        define_qlass_under<QTextBlockFormat, QTextFormat>(rb_mQt6QtGui, "QTextBlockFormat")
            // RubyQt6-Defined Functions
            .define_method("set_alignment", [](QTextBlockFormat *self, Qt::AlignmentFlag alignment) -> void { return self->setAlignment(alignment); }, Arg("alignment"))
            // Constructor
            .define_constructor(Constructor<QTextBlockFormat>())
            // Public Functions
            .define_method("alignment", &QTextBlockFormat::alignment)
            .define_method("bottom_margin", &QTextBlockFormat::bottomMargin)
            .define_method("heading_level", &QTextBlockFormat::headingLevel)
            .define_method("indent", &QTextBlockFormat::indent)
            .define_method("valid?", &QTextBlockFormat::isValid)
            .define_method("left_margin", &QTextBlockFormat::leftMargin)
            .define_method<qreal (QTextBlockFormat::*)() const>("line_height", &QTextBlockFormat::lineHeight)
            .define_method<qreal (QTextBlockFormat::*)(qreal, qreal) const>("line_height", &QTextBlockFormat::lineHeight, Arg("script_line_height"), Arg("scaling"))
            .define_method("line_height_type", &QTextBlockFormat::lineHeightType)
            .define_method("marker", &QTextBlockFormat::marker)
            .define_method("non_breakable_lines", &QTextBlockFormat::nonBreakableLines)
            .define_method("page_break_policy", &QTextBlockFormat::pageBreakPolicy)
            .define_method("right_margin", &QTextBlockFormat::rightMargin)
            .define_method("set_alignment", &QTextBlockFormat::setAlignment, Arg("alignment"))
            .define_method("set_bottom_margin", &QTextBlockFormat::setBottomMargin, Arg("margin"))
            .define_method("set_heading_level", &QTextBlockFormat::setHeadingLevel, Arg("alevel"))
            .define_method("set_indent", &QTextBlockFormat::setIndent, Arg("indent"))
            .define_method("set_left_margin", &QTextBlockFormat::setLeftMargin, Arg("margin"))
            .define_method("set_line_height", &QTextBlockFormat::setLineHeight, Arg("height"), Arg("height_type"))
            .define_method("set_marker", &QTextBlockFormat::setMarker, Arg("marker"))
            .define_method("set_non_breakable_lines", &QTextBlockFormat::setNonBreakableLines, Arg("b"))
            .define_method("set_page_break_policy", &QTextBlockFormat::setPageBreakPolicy, Arg("flags"))
            .define_method("set_right_margin", &QTextBlockFormat::setRightMargin, Arg("margin"))
            .define_method("set_tab_positions", &QTextBlockFormat::setTabPositions, Arg("tabs"))
            .define_method("set_text_indent", &QTextBlockFormat::setTextIndent, Arg("aindent"))
            .define_method("set_top_margin", &QTextBlockFormat::setTopMargin, Arg("margin"))
            .define_method("tab_positions", &QTextBlockFormat::tabPositions)
            .define_method("text_indent", &QTextBlockFormat::textIndent)
            .define_method("top_margin", &QTextBlockFormat::topMargin);

    Data_Type<QTextBlockFormat::LineHeightTypes> rb_cQTextBlockFormatLineHeightTypes =
        // RubyQt6::QtGui::QTextBlockFormat::LineHeightTypes
        define_qenum_under<QTextBlockFormat::LineHeightTypes>(rb_cQTextBlockFormat, "LineHeightTypes");
        define_qenum_value_under(rb_cQTextBlockFormatLineHeightTypes, "SingleHeight", QTextBlockFormat::LineHeightTypes::SingleHeight);
        define_qenum_value_under(rb_cQTextBlockFormatLineHeightTypes, "ProportionalHeight", QTextBlockFormat::LineHeightTypes::ProportionalHeight);
        define_qenum_value_under(rb_cQTextBlockFormatLineHeightTypes, "FixedHeight", QTextBlockFormat::LineHeightTypes::FixedHeight);
        define_qenum_value_under(rb_cQTextBlockFormatLineHeightTypes, "MinimumHeight", QTextBlockFormat::LineHeightTypes::MinimumHeight);
        define_qenum_value_under(rb_cQTextBlockFormatLineHeightTypes, "LineDistanceHeight", QTextBlockFormat::LineHeightTypes::LineDistanceHeight);

    Data_Type<QTextBlockFormat::MarkerType> rb_cQTextBlockFormatMarkerType =
        // RubyQt6::QtGui::QTextBlockFormat::MarkerType
        define_qenum_under<QTextBlockFormat::MarkerType>(rb_cQTextBlockFormat, "MarkerType");
        define_qenum_value_under(rb_cQTextBlockFormatMarkerType, "NoMarker", QTextBlockFormat::MarkerType::NoMarker);
        define_qenum_value_under(rb_cQTextBlockFormatMarkerType, "Unchecked", QTextBlockFormat::MarkerType::Unchecked);
        define_qenum_value_under(rb_cQTextBlockFormatMarkerType, "Checked", QTextBlockFormat::MarkerType::Checked);

    rb_cQTextCharFormat =
        // RubyQt6::QtGui::QTextCharFormat
        define_qlass_under<QTextCharFormat, QTextFormat>(rb_mQt6QtGui, "QTextCharFormat")
            // Constructor
            .define_constructor(Constructor<QTextCharFormat>())
            // Public Functions
            .define_method("anchor_href", &QTextCharFormat::anchorHref)
            .define_method("anchor_names", &QTextCharFormat::anchorNames)
            .define_method("baseline_offset", &QTextCharFormat::baselineOffset)
            .define_method("font", &QTextCharFormat::font)
            .define_method("font_capitalization", &QTextCharFormat::fontCapitalization)
            .define_method("font_families", &QTextCharFormat::fontFamilies)
            .define_method("font_fixed_pitch", &QTextCharFormat::fontFixedPitch)
            .define_method("font_hinting_preference", &QTextCharFormat::fontHintingPreference)
            .define_method("font_italic", &QTextCharFormat::fontItalic)
            .define_method("font_kerning", &QTextCharFormat::fontKerning)
            .define_method("font_letter_spacing", &QTextCharFormat::fontLetterSpacing)
            .define_method("font_letter_spacing_type", &QTextCharFormat::fontLetterSpacingType)
            .define_method("font_overline", &QTextCharFormat::fontOverline)
            .define_method("font_point_size", &QTextCharFormat::fontPointSize)
            .define_method("font_stretch", &QTextCharFormat::fontStretch)
            .define_method("font_strike_out", &QTextCharFormat::fontStrikeOut)
            .define_method("font_style_hint", &QTextCharFormat::fontStyleHint)
            .define_method("font_style_name", &QTextCharFormat::fontStyleName)
            .define_method("font_style_strategy", &QTextCharFormat::fontStyleStrategy)
            .define_method("font_underline", &QTextCharFormat::fontUnderline)
            .define_method("font_weight", &QTextCharFormat::fontWeight)
            .define_method("font_word_spacing", &QTextCharFormat::fontWordSpacing)
            .define_method("anchor?", &QTextCharFormat::isAnchor)
            .define_method("valid?", &QTextCharFormat::isValid)
            .define_method("set_anchor", &QTextCharFormat::setAnchor, Arg("anchor"))
            .define_method("set_anchor_href", &QTextCharFormat::setAnchorHref, Arg("value"))
            .define_method("set_anchor_names", &QTextCharFormat::setAnchorNames, Arg("names"))
            .define_method("set_baseline_offset", &QTextCharFormat::setBaselineOffset, Arg("baseline"))
            .define_method("set_font", &QTextCharFormat::setFont, Arg("font"), Arg("behavior") = static_cast<QTextCharFormat::FontPropertiesInheritanceBehavior>(QTextCharFormat::FontPropertiesInheritanceBehavior::FontPropertiesAll))
            .define_method("set_font_capitalization", &QTextCharFormat::setFontCapitalization, Arg("capitalization"))
            .define_method("set_font_families", &QTextCharFormat::setFontFamilies, Arg("families"))
            .define_method("set_font_fixed_pitch", &QTextCharFormat::setFontFixedPitch, Arg("fixed_pitch"))
            .define_method("set_font_hinting_preference", &QTextCharFormat::setFontHintingPreference, Arg("hinting_preference"))
            .define_method("set_font_italic", &QTextCharFormat::setFontItalic, Arg("italic"))
            .define_method("set_font_kerning", &QTextCharFormat::setFontKerning, Arg("enable"))
            .define_method("set_font_letter_spacing", &QTextCharFormat::setFontLetterSpacing, Arg("spacing"))
            .define_method("set_font_letter_spacing_type", &QTextCharFormat::setFontLetterSpacingType, Arg("letter_spacing_type"))
            .define_method("set_font_overline", &QTextCharFormat::setFontOverline, Arg("overline"))
            .define_method("set_font_point_size", &QTextCharFormat::setFontPointSize, Arg("size"))
            .define_method("set_font_stretch", &QTextCharFormat::setFontStretch, Arg("factor"))
            .define_method("set_font_strike_out", &QTextCharFormat::setFontStrikeOut, Arg("strike_out"))
            .define_method("set_font_style_hint", &QTextCharFormat::setFontStyleHint, Arg("hint"), Arg("strategy") = static_cast<QFont::StyleStrategy>(QFont::PreferDefault))
            .define_method("set_font_style_name", &QTextCharFormat::setFontStyleName, Arg("style_name"))
            .define_method("set_font_style_strategy", &QTextCharFormat::setFontStyleStrategy, Arg("strategy"))
            .define_method("set_font_underline", &QTextCharFormat::setFontUnderline, Arg("underline"))
            .define_method("set_font_weight", &QTextCharFormat::setFontWeight, Arg("weight"))
            .define_method("set_font_word_spacing", &QTextCharFormat::setFontWordSpacing, Arg("spacing"))
            .define_method("set_sub_script_baseline", &QTextCharFormat::setSubScriptBaseline, Arg("baseline"))
            .define_method("set_super_script_baseline", &QTextCharFormat::setSuperScriptBaseline, Arg("baseline"))
            .define_method("set_table_cell_column_span", &QTextCharFormat::setTableCellColumnSpan, Arg("table_cell_column_span"))
            .define_method("set_table_cell_row_span", &QTextCharFormat::setTableCellRowSpan, Arg("table_cell_row_span"))
            .define_method("set_text_outline", &QTextCharFormat::setTextOutline, Arg("pen"))
            .define_method("set_tool_tip", &QTextCharFormat::setToolTip, Arg("tip"))
            .define_method("set_underline_color", &QTextCharFormat::setUnderlineColor, Arg("color"))
            .define_method("set_underline_style", &QTextCharFormat::setUnderlineStyle, Arg("style"))
            .define_method("set_vertical_alignment", &QTextCharFormat::setVerticalAlignment, Arg("alignment"))
            .define_method("sub_script_baseline", &QTextCharFormat::subScriptBaseline)
            .define_method("super_script_baseline", &QTextCharFormat::superScriptBaseline)
            .define_method("table_cell_column_span", &QTextCharFormat::tableCellColumnSpan)
            .define_method("table_cell_row_span", &QTextCharFormat::tableCellRowSpan)
            .define_method("text_outline", &QTextCharFormat::textOutline)
            .define_method("tool_tip", &QTextCharFormat::toolTip)
            .define_method("underline_color", &QTextCharFormat::underlineColor)
            .define_method("underline_style", &QTextCharFormat::underlineStyle)
            .define_method("vertical_alignment", &QTextCharFormat::verticalAlignment);

   Data_Type<QTextCharFormat::VerticalAlignment> rb_cQTextCharFormatVerticalAlignment =
        // RubyQt6::QtGui::QTextCharFormat::VerticalAlignment
        define_qenum_under<QTextCharFormat::VerticalAlignment>(rb_cQTextCharFormat, "VerticalAlignment");
        define_qenum_value_under(rb_cQTextCharFormatVerticalAlignment, "AlignNormal", QTextCharFormat::VerticalAlignment::AlignNormal);
        define_qenum_value_under(rb_cQTextCharFormatVerticalAlignment, "AlignSuperScript", QTextCharFormat::VerticalAlignment::AlignSuperScript);
        define_qenum_value_under(rb_cQTextCharFormatVerticalAlignment, "AlignSubScript", QTextCharFormat::VerticalAlignment::AlignSubScript);
        define_qenum_value_under(rb_cQTextCharFormatVerticalAlignment, "AlignMiddle", QTextCharFormat::VerticalAlignment::AlignMiddle);
        define_qenum_value_under(rb_cQTextCharFormatVerticalAlignment, "AlignTop", QTextCharFormat::VerticalAlignment::AlignTop);
        define_qenum_value_under(rb_cQTextCharFormatVerticalAlignment, "AlignBottom", QTextCharFormat::VerticalAlignment::AlignBottom);
        define_qenum_value_under(rb_cQTextCharFormatVerticalAlignment, "AlignBaseline", QTextCharFormat::VerticalAlignment::AlignBaseline);

    Data_Type<QTextCharFormat::UnderlineStyle> rb_cQTextCharFormatUnderlineStyle =
        // RubyQt6::QtGui::QTextCharFormat::UnderlineStyle
        define_qenum_under<QTextCharFormat::UnderlineStyle>(rb_cQTextCharFormat, "UnderlineStyle");
        define_qenum_value_under(rb_cQTextCharFormatUnderlineStyle, "NoUnderline", QTextCharFormat::UnderlineStyle::NoUnderline);
        define_qenum_value_under(rb_cQTextCharFormatUnderlineStyle, "SingleUnderline", QTextCharFormat::UnderlineStyle::SingleUnderline);
        define_qenum_value_under(rb_cQTextCharFormatUnderlineStyle, "DashUnderline", QTextCharFormat::UnderlineStyle::DashUnderline);
        define_qenum_value_under(rb_cQTextCharFormatUnderlineStyle, "DotLine", QTextCharFormat::UnderlineStyle::DotLine);
        define_qenum_value_under(rb_cQTextCharFormatUnderlineStyle, "DashDotLine", QTextCharFormat::UnderlineStyle::DashDotLine);
        define_qenum_value_under(rb_cQTextCharFormatUnderlineStyle, "DashDotDotLine", QTextCharFormat::UnderlineStyle::DashDotDotLine);
        define_qenum_value_under(rb_cQTextCharFormatUnderlineStyle, "WaveUnderline", QTextCharFormat::UnderlineStyle::WaveUnderline);
        define_qenum_value_under(rb_cQTextCharFormatUnderlineStyle, "SpellCheckUnderline", QTextCharFormat::UnderlineStyle::SpellCheckUnderline);

    Data_Type<QTextCharFormat::FontPropertiesInheritanceBehavior> rb_cQTextCharFormatFontPropertiesInheritanceBehavior =
        // RubyQt6::QtGui::QTextCharFormat::FontPropertiesInheritanceBehavior
        define_qenum_under<QTextCharFormat::FontPropertiesInheritanceBehavior>(rb_cQTextCharFormat, "FontPropertiesInheritanceBehavior");
        define_qenum_value_under(rb_cQTextCharFormatFontPropertiesInheritanceBehavior, "FontPropertiesSpecifiedOnly", QTextCharFormat::FontPropertiesInheritanceBehavior::FontPropertiesSpecifiedOnly);
        define_qenum_value_under(rb_cQTextCharFormatFontPropertiesInheritanceBehavior, "FontPropertiesAll", QTextCharFormat::FontPropertiesInheritanceBehavior::FontPropertiesAll);

    rb_cQTextImageFormat =
        // RubyQt6::QtGui::QTextImageFormat
        define_qlass_under<QTextImageFormat, QTextCharFormat>(rb_mQt6QtGui, "QTextImageFormat")
            // Constructor
            .define_constructor(Constructor<QTextImageFormat>())
            // Public Functions
            .define_method("height", &QTextImageFormat::height)
            .define_method("valid?", &QTextImageFormat::isValid)
            .define_method("maximum_width", &QTextImageFormat::maximumWidth)
            .define_method("name", &QTextImageFormat::name)
            .define_method("quality", &QTextImageFormat::quality)
            .define_method("set_height", &QTextImageFormat::setHeight, Arg("height"))
            .define_method("set_maximum_width", &QTextImageFormat::setMaximumWidth, Arg("max_width"))
            .define_method("set_name", &QTextImageFormat::setName, Arg("name"))
            .define_method<void (QTextImageFormat::*)(int)>("set_quality", &QTextImageFormat::setQuality, Arg("quality"))
            .define_method("set_width", &QTextImageFormat::setWidth, Arg("width"))
            .define_method("width", &QTextImageFormat::width);

    rb_cQTextTableCellFormat =
        // RubyQt6::QtGui::QTextTableCellFormat
        define_qlass_under<QTextTableCellFormat, QTextCharFormat>(rb_mQt6QtGui, "QTextTableCellFormat")
            // Constructor
            .define_constructor(Constructor<QTextTableCellFormat>())
            // Public Functions
            .define_method("bottom_border", &QTextTableCellFormat::bottomBorder)
            .define_method("bottom_border_brush", &QTextTableCellFormat::bottomBorderBrush)
            .define_method("bottom_border_style", &QTextTableCellFormat::bottomBorderStyle)
            .define_method("bottom_padding", &QTextTableCellFormat::bottomPadding)
            .define_method("valid?", &QTextTableCellFormat::isValid)
            .define_method("left_border", &QTextTableCellFormat::leftBorder)
            .define_method("left_border_brush", &QTextTableCellFormat::leftBorderBrush)
            .define_method("left_border_style", &QTextTableCellFormat::leftBorderStyle)
            .define_method("left_padding", &QTextTableCellFormat::leftPadding)
            .define_method("right_border", &QTextTableCellFormat::rightBorder)
            .define_method("right_border_brush", &QTextTableCellFormat::rightBorderBrush)
            .define_method("right_border_style", &QTextTableCellFormat::rightBorderStyle)
            .define_method("right_padding", &QTextTableCellFormat::rightPadding)
            .define_method("set_border", &QTextTableCellFormat::setBorder, Arg("width"))
            .define_method("set_border_brush", &QTextTableCellFormat::setBorderBrush, Arg("brush"))
            .define_method("set_border_style", &QTextTableCellFormat::setBorderStyle, Arg("style"))
            .define_method("set_bottom_border", &QTextTableCellFormat::setBottomBorder, Arg("width"))
            .define_method("set_bottom_border_brush", &QTextTableCellFormat::setBottomBorderBrush, Arg("brush"))
            .define_method("set_bottom_border_style", &QTextTableCellFormat::setBottomBorderStyle, Arg("style"))
            .define_method("set_bottom_padding", &QTextTableCellFormat::setBottomPadding, Arg("padding"))
            .define_method("set_left_border", &QTextTableCellFormat::setLeftBorder, Arg("width"))
            .define_method("set_left_border_brush", &QTextTableCellFormat::setLeftBorderBrush, Arg("brush"))
            .define_method("set_left_border_style", &QTextTableCellFormat::setLeftBorderStyle, Arg("style"))
            .define_method("set_left_padding", &QTextTableCellFormat::setLeftPadding, Arg("padding"))
            .define_method("set_padding", &QTextTableCellFormat::setPadding, Arg("padding"))
            .define_method("set_right_border", &QTextTableCellFormat::setRightBorder, Arg("width"))
            .define_method("set_right_border_brush", &QTextTableCellFormat::setRightBorderBrush, Arg("brush"))
            .define_method("set_right_border_style", &QTextTableCellFormat::setRightBorderStyle, Arg("style"))
            .define_method("set_right_padding", &QTextTableCellFormat::setRightPadding, Arg("padding"))
            .define_method("set_top_border", &QTextTableCellFormat::setTopBorder, Arg("width"))
            .define_method("set_top_border_brush", &QTextTableCellFormat::setTopBorderBrush, Arg("brush"))
            .define_method("set_top_border_style", &QTextTableCellFormat::setTopBorderStyle, Arg("style"))
            .define_method("set_top_padding", &QTextTableCellFormat::setTopPadding, Arg("padding"))
            .define_method("top_border", &QTextTableCellFormat::topBorder)
            .define_method("top_border_brush", &QTextTableCellFormat::topBorderBrush)
            .define_method("top_border_style", &QTextTableCellFormat::topBorderStyle)
            .define_method("top_padding", &QTextTableCellFormat::topPadding);

    rb_cQTextFrameFormat =
        // RubyQt6::QtGui::QTextFrameFormat
        define_qlass_under<QTextFrameFormat, QTextFormat>(rb_mQt6QtGui, "QTextFrameFormat")
            // Constructor
            .define_constructor(Constructor<QTextFrameFormat>())
            // Public Functions
            .define_method("border", &QTextFrameFormat::border)
            .define_method("border_brush", &QTextFrameFormat::borderBrush)
            .define_method("border_style", &QTextFrameFormat::borderStyle)
            .define_method("bottom_margin", &QTextFrameFormat::bottomMargin)
            .define_method("height", &QTextFrameFormat::height)
            .define_method("valid?", &QTextFrameFormat::isValid)
            .define_method("left_margin", &QTextFrameFormat::leftMargin)
            .define_method("margin", &QTextFrameFormat::margin)
            .define_method("padding", &QTextFrameFormat::padding)
            .define_method("page_break_policy", &QTextFrameFormat::pageBreakPolicy)
            .define_method("position", &QTextFrameFormat::position)
            .define_method("right_margin", &QTextFrameFormat::rightMargin)
            .define_method("set_border", &QTextFrameFormat::setBorder, Arg("border"))
            .define_method("set_border_brush", &QTextFrameFormat::setBorderBrush, Arg("brush"))
            .define_method("set_border_style", &QTextFrameFormat::setBorderStyle, Arg("style"))
            .define_method("set_bottom_margin", &QTextFrameFormat::setBottomMargin, Arg("margin"))
            .define_method<void (QTextFrameFormat::*)(const QTextLength &)>("set_height", &QTextFrameFormat::setHeight, Arg("height"))
            .define_method<void (QTextFrameFormat::*)(qreal)>("set_height", &QTextFrameFormat::setHeight, Arg("height"))
            .define_method("set_left_margin", &QTextFrameFormat::setLeftMargin, Arg("margin"))
            .define_method("set_margin", &QTextFrameFormat::setMargin, Arg("margin"))
            .define_method("set_padding", &QTextFrameFormat::setPadding, Arg("padding"))
            .define_method("set_page_break_policy", &QTextFrameFormat::setPageBreakPolicy, Arg("flags"))
            .define_method("set_position", &QTextFrameFormat::setPosition, Arg("f"))
            .define_method("set_right_margin", &QTextFrameFormat::setRightMargin, Arg("margin"))
            .define_method("set_top_margin", &QTextFrameFormat::setTopMargin, Arg("margin"))
            .define_method<void (QTextFrameFormat::*)(const QTextLength &)>("set_width", &QTextFrameFormat::setWidth, Arg("length"))
            .define_method<void (QTextFrameFormat::*)(qreal)>("set_width", &QTextFrameFormat::setWidth, Arg("width"))
            .define_method("top_margin", &QTextFrameFormat::topMargin)
            .define_method("width", &QTextFrameFormat::width);

    Data_Type<QTextFrameFormat::Position> rb_cQTextFrameFormatPosition =
        // RubyQt6::QtGui::QTextFrameFormat::Position
        define_qenum_under<QTextFrameFormat::Position>(rb_cQTextFrameFormat, "Position");
        define_qenum_value_under(rb_cQTextFrameFormatPosition, "InFlow", QTextFrameFormat::Position::InFlow);
        define_qenum_value_under(rb_cQTextFrameFormatPosition, "FloatLeft", QTextFrameFormat::Position::FloatLeft);
        define_qenum_value_under(rb_cQTextFrameFormatPosition, "FloatRight", QTextFrameFormat::Position::FloatRight);

    Data_Type<QTextFrameFormat::BorderStyle> rb_cQTextFrameFormatBorderStyle =
        // RubyQt6::QtGui::QTextFrameFormat::BorderStyle
        define_qenum_under<QTextFrameFormat::BorderStyle>(rb_cQTextFrameFormat, "BorderStyle");
        define_qenum_value_under(rb_cQTextFrameFormatBorderStyle, "BorderStyle_None", QTextFrameFormat::BorderStyle::BorderStyle_None);
        define_qenum_value_under(rb_cQTextFrameFormatBorderStyle, "BorderStyle_Dotted", QTextFrameFormat::BorderStyle::BorderStyle_Dotted);
        define_qenum_value_under(rb_cQTextFrameFormatBorderStyle, "BorderStyle_Dashed", QTextFrameFormat::BorderStyle::BorderStyle_Dashed);
        define_qenum_value_under(rb_cQTextFrameFormatBorderStyle, "BorderStyle_Solid", QTextFrameFormat::BorderStyle::BorderStyle_Solid);
        define_qenum_value_under(rb_cQTextFrameFormatBorderStyle, "BorderStyle_Double", QTextFrameFormat::BorderStyle::BorderStyle_Double);
        define_qenum_value_under(rb_cQTextFrameFormatBorderStyle, "BorderStyle_DotDash", QTextFrameFormat::BorderStyle::BorderStyle_DotDash);
        define_qenum_value_under(rb_cQTextFrameFormatBorderStyle, "BorderStyle_DotDotDash", QTextFrameFormat::BorderStyle::BorderStyle_DotDotDash);
        define_qenum_value_under(rb_cQTextFrameFormatBorderStyle, "BorderStyle_Groove", QTextFrameFormat::BorderStyle::BorderStyle_Groove);
        define_qenum_value_under(rb_cQTextFrameFormatBorderStyle, "BorderStyle_Ridge", QTextFrameFormat::BorderStyle::BorderStyle_Ridge);
        define_qenum_value_under(rb_cQTextFrameFormatBorderStyle, "BorderStyle_Inset", QTextFrameFormat::BorderStyle::BorderStyle_Inset);
        define_qenum_value_under(rb_cQTextFrameFormatBorderStyle, "BorderStyle_Outset", QTextFrameFormat::BorderStyle::BorderStyle_Outset);

    rb_cQTextTableFormat =
        // RubyQt6::QtGui::QTextTableFormat
        define_qlass_under<QTextTableFormat, QTextFrameFormat>(rb_mQt6QtGui, "QTextTableFormat")
            // RubyQt6-Defined Functions
            .define_method("set_alignment", [](QTextTableFormat *self, Qt::AlignmentFlag alignment) -> void { return self->setAlignment(alignment); }, Arg("alignment"))
            // Constructor
            .define_constructor(Constructor<QTextTableFormat>())
            // Public Functions
            .define_method("alignment", &QTextTableFormat::alignment)
            .define_method("border_collapse", &QTextTableFormat::borderCollapse)
            .define_method("cell_padding", &QTextTableFormat::cellPadding)
            .define_method("cell_spacing", &QTextTableFormat::cellSpacing)
            .define_method("clear_column_width_constraints", &QTextTableFormat::clearColumnWidthConstraints)
            .define_method("column_width_constraints", &QTextTableFormat::columnWidthConstraints)
            .define_method("columns", &QTextTableFormat::columns)
            .define_method("header_row_count", &QTextTableFormat::headerRowCount)
            .define_method("valid?", &QTextTableFormat::isValid)
            .define_method("set_alignment", &QTextTableFormat::setAlignment, Arg("alignment"))
            .define_method("set_border_collapse", &QTextTableFormat::setBorderCollapse, Arg("border_collapse"))
            .define_method("set_cell_padding", &QTextTableFormat::setCellPadding, Arg("padding"))
            .define_method("set_cell_spacing", &QTextTableFormat::setCellSpacing, Arg("spacing"))
            .define_method("_set_column_width_constraints", &QTextTableFormat::setColumnWidthConstraints, Arg("constraints"))
            .define_method("set_columns", &QTextTableFormat::setColumns, Arg("columns"))
            .define_method("set_header_row_count", &QTextTableFormat::setHeaderRowCount, Arg("count"));

    rb_cQTextListFormat =
        // RubyQt6::QtGui::QTextListFormat
        define_qlass_under<QTextListFormat, QTextFormat>(rb_mQt6QtGui, "QTextListFormat")
            // Constructor
            .define_constructor(Constructor<QTextListFormat>())
            // Public Functions
            .define_method("indent", &QTextListFormat::indent)
            .define_method("valid?", &QTextListFormat::isValid)
            .define_method("number_prefix", &QTextListFormat::numberPrefix)
            .define_method("number_suffix", &QTextListFormat::numberSuffix)
            .define_method("set_indent", &QTextListFormat::setIndent, Arg("indent"))
            .define_method("set_number_prefix", &QTextListFormat::setNumberPrefix, Arg("number_prefix"))
            .define_method("set_number_suffix", &QTextListFormat::setNumberSuffix, Arg("number_suffix"))
            .define_method("set_start", &QTextListFormat::setStart, Arg("indent"))
            .define_method("set_style", &QTextListFormat::setStyle, Arg("style"))
            .define_method("start", &QTextListFormat::start)
            .define_method("style", &QTextListFormat::style);

    Data_Type<QTextListFormat::Style> rb_cQTextListFormatStyle =
        // RubyQt6::QtGui::QTextListFormat::Style
        define_qenum_under<QTextListFormat::Style>(rb_cQTextListFormat, "Style");
        define_qenum_value_under(rb_cQTextListFormatStyle, "ListDisc", QTextListFormat::Style::ListDisc);
        define_qenum_value_under(rb_cQTextListFormatStyle, "ListCircle", QTextListFormat::Style::ListCircle);
        define_qenum_value_under(rb_cQTextListFormatStyle, "ListSquare", QTextListFormat::Style::ListSquare);
        define_qenum_value_under(rb_cQTextListFormatStyle, "ListDecimal", QTextListFormat::Style::ListDecimal);
        define_qenum_value_under(rb_cQTextListFormatStyle, "ListLowerAlpha", QTextListFormat::Style::ListLowerAlpha);
        define_qenum_value_under(rb_cQTextListFormatStyle, "ListUpperAlpha", QTextListFormat::Style::ListUpperAlpha);
        define_qenum_value_under(rb_cQTextListFormatStyle, "ListLowerRoman", QTextListFormat::Style::ListLowerRoman);
        define_qenum_value_under(rb_cQTextListFormatStyle, "ListUpperRoman", QTextListFormat::Style::ListUpperRoman);
        define_qenum_value_under(rb_cQTextListFormatStyle, "ListStyleUndefined", QTextListFormat::Style::ListStyleUndefined);

    rb_cQTextLength =
        // RubyQt6::QtGui::QTextLength
        define_qlass_under<QTextLength>(rb_mQt6QtGui, "QTextLength")
            // Constructor
            .define_constructor(Constructor<QTextLength>())
            .define_constructor(Constructor<QTextLength, QTextLength::Type, qreal>(), Arg("type"), Arg("value"))
            // Public Functions
            .define_method("raw_value", &QTextLength::rawValue)
            .define_method("type", &QTextLength::type)
            .define_method("value", &QTextLength::value, Arg("maximum_length"));

    Data_Type<QTextLength::Type> rb_cQTextLengthType =
        // RubyQt6::QtGui::QTextLength::Type
        define_qenum_under<QTextLength::Type>(rb_cQTextLength, "Type");
        define_qenum_value_under(rb_cQTextLengthType, "VariableLength", QTextLength::Type::VariableLength);
        define_qenum_value_under(rb_cQTextLengthType, "FixedLength", QTextLength::Type::FixedLength);
        define_qenum_value_under(rb_cQTextLengthType, "PercentageLength", QTextLength::Type::PercentageLength);
}

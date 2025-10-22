#include "qtextformat-rb.hpp"
#include <qtextformat.h>
#include <rice/qenum.hpp>
#include <rice/qflags.hpp>

using namespace Rice;

Rice::Class rb_cQTextFormat;
Rice::Class rb_cQTextBlockFormat;
Rice::Class rb_cQTextCharFormat;
Rice::Class rb_cQTextImageFormat;
Rice::Class rb_cQTextTableCellFormat;
Rice::Class rb_cQTextFrameFormat;
Rice::Class rb_cQTextTableFormat;
Rice::Class rb_cQTextListFormat;

void Init_qtextformat(Rice::Module rb_mQt6QtGui)
{
    rb_cQTextFormat =
        // RubyQt6::QtGui::QTextFormat
        define_class_under<QTextFormat>(rb_mQt6QtGui, "QTextFormat")
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
            .define_method("swap", &QTextFormat::swap, Arg("other"))
            .define_method("to_block_format", &QTextFormat::toBlockFormat)
            .define_method("to_char_format", &QTextFormat::toCharFormat)
            .define_method("to_frame_format", &QTextFormat::toFrameFormat)
            .define_method("to_image_format", &QTextFormat::toImageFormat)
            .define_method("to_list_format", &QTextFormat::toListFormat)
            .define_method("to_table_cell_format", &QTextFormat::toTableCellFormat)
            .define_method("to_table_format", &QTextFormat::toTableFormat)
            .define_method("type", &QTextFormat::type);

    Enum<QTextFormat::FormatType> rb_cQTextFormatFormatType =
        // RubyQt6::QtGui::QTextFormat::FormatType
        define_qenum_under<QTextFormat::FormatType>("FormatType", rb_cQTextFormat)
            .define_value("InvalidFormat", QTextFormat::FormatType::InvalidFormat)
            .define_value("BlockFormat", QTextFormat::FormatType::BlockFormat)
            .define_value("CharFormat", QTextFormat::FormatType::CharFormat)
            .define_value("ListFormat", QTextFormat::FormatType::ListFormat)
            .define_value("FrameFormat", QTextFormat::FormatType::FrameFormat)
            .define_value("UserFormat", QTextFormat::FormatType::UserFormat);

    Enum<QTextFormat::Property> rb_cQTextFormatProperty =
        // RubyQt6::QtGui::QTextFormat::Property
        define_qenum_under<QTextFormat::Property>("Property", rb_cQTextFormat)
            .define_value("ObjectIndex", QTextFormat::Property::ObjectIndex)
            .define_value("CssFloat", QTextFormat::Property::CssFloat)
            .define_value("LayoutDirection", QTextFormat::Property::LayoutDirection)
            .define_value("OutlinePen", QTextFormat::Property::OutlinePen)
            .define_value("BackgroundBrush", QTextFormat::Property::BackgroundBrush)
            .define_value("ForegroundBrush", QTextFormat::Property::ForegroundBrush)
            .define_value("BackgroundImageUrl", QTextFormat::Property::BackgroundImageUrl)
            .define_value("BlockAlignment", QTextFormat::Property::BlockAlignment)
            .define_value("BlockTopMargin", QTextFormat::Property::BlockTopMargin)
            .define_value("BlockBottomMargin", QTextFormat::Property::BlockBottomMargin)
            .define_value("BlockLeftMargin", QTextFormat::Property::BlockLeftMargin)
            .define_value("BlockRightMargin", QTextFormat::Property::BlockRightMargin)
            .define_value("TextIndent", QTextFormat::Property::TextIndent)
            .define_value("TabPositions", QTextFormat::Property::TabPositions)
            .define_value("BlockIndent", QTextFormat::Property::BlockIndent)
            .define_value("LineHeight", QTextFormat::Property::LineHeight)
            .define_value("LineHeightType", QTextFormat::Property::LineHeightType)
            .define_value("BlockNonBreakableLines", QTextFormat::Property::BlockNonBreakableLines)
            .define_value("BlockTrailingHorizontalRulerWidth", QTextFormat::Property::BlockTrailingHorizontalRulerWidth)
            .define_value("HeadingLevel", QTextFormat::Property::HeadingLevel)
            .define_value("BlockQuoteLevel", QTextFormat::Property::BlockQuoteLevel)
            .define_value("BlockCodeLanguage", QTextFormat::Property::BlockCodeLanguage)
            .define_value("BlockCodeFence", QTextFormat::Property::BlockCodeFence)
            .define_value("BlockMarker", QTextFormat::Property::BlockMarker)
            .define_value("FirstFontProperty", QTextFormat::Property::FirstFontProperty)
            .define_value("FontCapitalization", QTextFormat::Property::FontCapitalization)
            .define_value("FontLetterSpacing", QTextFormat::Property::FontLetterSpacing)
            .define_value("FontWordSpacing", QTextFormat::Property::FontWordSpacing)
            .define_value("FontStyleHint", QTextFormat::Property::FontStyleHint)
            .define_value("FontStyleStrategy", QTextFormat::Property::FontStyleStrategy)
            .define_value("FontKerning", QTextFormat::Property::FontKerning)
            .define_value("FontHintingPreference", QTextFormat::Property::FontHintingPreference)
            .define_value("FontFamilies", QTextFormat::Property::FontFamilies)
            .define_value("FontStyleName", QTextFormat::Property::FontStyleName)
            .define_value("FontLetterSpacingType", QTextFormat::Property::FontLetterSpacingType)
            .define_value("FontStretch", QTextFormat::Property::FontStretch)
            .define_value("FontFamily", QTextFormat::Property::FontFamily)
            .define_value("FontPointSize", QTextFormat::Property::FontPointSize)
            .define_value("FontSizeAdjustment", QTextFormat::Property::FontSizeAdjustment)
            .define_value("FontSizeIncrement", QTextFormat::Property::FontSizeIncrement)
            .define_value("FontWeight", QTextFormat::Property::FontWeight)
            .define_value("FontItalic", QTextFormat::Property::FontItalic)
            .define_value("FontUnderline", QTextFormat::Property::FontUnderline)
            .define_value("FontOverline", QTextFormat::Property::FontOverline)
            .define_value("FontStrikeOut", QTextFormat::Property::FontStrikeOut)
            .define_value("FontFixedPitch", QTextFormat::Property::FontFixedPitch)
            .define_value("FontPixelSize", QTextFormat::Property::FontPixelSize)
            .define_value("LastFontProperty", QTextFormat::Property::LastFontProperty)
            .define_value("TextUnderlineColor", QTextFormat::Property::TextUnderlineColor)
            .define_value("TextVerticalAlignment", QTextFormat::Property::TextVerticalAlignment)
            .define_value("TextOutline", QTextFormat::Property::TextOutline)
            .define_value("TextUnderlineStyle", QTextFormat::Property::TextUnderlineStyle)
            .define_value("TextToolTip", QTextFormat::Property::TextToolTip)
            .define_value("TextSuperScriptBaseline", QTextFormat::Property::TextSuperScriptBaseline)
            .define_value("TextSubScriptBaseline", QTextFormat::Property::TextSubScriptBaseline)
            .define_value("TextBaselineOffset", QTextFormat::Property::TextBaselineOffset)
            .define_value("IsAnchor", QTextFormat::Property::IsAnchor)
            .define_value("AnchorHref", QTextFormat::Property::AnchorHref)
            .define_value("AnchorName", QTextFormat::Property::AnchorName)
            .define_value("OldFontLetterSpacingType", QTextFormat::Property::OldFontLetterSpacingType)
            .define_value("OldFontStretch", QTextFormat::Property::OldFontStretch)
            .define_value("OldTextUnderlineColor", QTextFormat::Property::OldTextUnderlineColor)
            .define_value("OldFontFamily", QTextFormat::Property::OldFontFamily)
            .define_value("ObjectType", QTextFormat::Property::ObjectType)
            .define_value("ListStyle", QTextFormat::Property::ListStyle)
            .define_value("ListIndent", QTextFormat::Property::ListIndent)
            .define_value("ListNumberPrefix", QTextFormat::Property::ListNumberPrefix)
            .define_value("ListNumberSuffix", QTextFormat::Property::ListNumberSuffix)
            .define_value("ListStart", QTextFormat::Property::ListStart)
            .define_value("FrameBorder", QTextFormat::Property::FrameBorder)
            .define_value("FrameMargin", QTextFormat::Property::FrameMargin)
            .define_value("FramePadding", QTextFormat::Property::FramePadding)
            .define_value("FrameWidth", QTextFormat::Property::FrameWidth)
            .define_value("FrameHeight", QTextFormat::Property::FrameHeight)
            .define_value("FrameTopMargin", QTextFormat::Property::FrameTopMargin)
            .define_value("FrameBottomMargin", QTextFormat::Property::FrameBottomMargin)
            .define_value("FrameLeftMargin", QTextFormat::Property::FrameLeftMargin)
            .define_value("FrameRightMargin", QTextFormat::Property::FrameRightMargin)
            .define_value("FrameBorderBrush", QTextFormat::Property::FrameBorderBrush)
            .define_value("FrameBorderStyle", QTextFormat::Property::FrameBorderStyle)
            .define_value("TableColumns", QTextFormat::Property::TableColumns)
            .define_value("TableColumnWidthConstraints", QTextFormat::Property::TableColumnWidthConstraints)
            .define_value("TableCellSpacing", QTextFormat::Property::TableCellSpacing)
            .define_value("TableCellPadding", QTextFormat::Property::TableCellPadding)
            .define_value("TableHeaderRowCount", QTextFormat::Property::TableHeaderRowCount)
            .define_value("TableBorderCollapse", QTextFormat::Property::TableBorderCollapse)
            .define_value("TableCellRowSpan", QTextFormat::Property::TableCellRowSpan)
            .define_value("TableCellColumnSpan", QTextFormat::Property::TableCellColumnSpan)
            .define_value("TableCellTopPadding", QTextFormat::Property::TableCellTopPadding)
            .define_value("TableCellBottomPadding", QTextFormat::Property::TableCellBottomPadding)
            .define_value("TableCellLeftPadding", QTextFormat::Property::TableCellLeftPadding)
            .define_value("TableCellRightPadding", QTextFormat::Property::TableCellRightPadding)
            .define_value("TableCellTopBorder", QTextFormat::Property::TableCellTopBorder)
            .define_value("TableCellBottomBorder", QTextFormat::Property::TableCellBottomBorder)
            .define_value("TableCellLeftBorder", QTextFormat::Property::TableCellLeftBorder)
            .define_value("TableCellRightBorder", QTextFormat::Property::TableCellRightBorder)
            .define_value("TableCellTopBorderStyle", QTextFormat::Property::TableCellTopBorderStyle)
            .define_value("TableCellBottomBorderStyle", QTextFormat::Property::TableCellBottomBorderStyle)
            .define_value("TableCellLeftBorderStyle", QTextFormat::Property::TableCellLeftBorderStyle)
            .define_value("TableCellRightBorderStyle", QTextFormat::Property::TableCellRightBorderStyle)
            .define_value("TableCellTopBorderBrush", QTextFormat::Property::TableCellTopBorderBrush)
            .define_value("TableCellBottomBorderBrush", QTextFormat::Property::TableCellBottomBorderBrush)
            .define_value("TableCellLeftBorderBrush", QTextFormat::Property::TableCellLeftBorderBrush)
            .define_value("TableCellRightBorderBrush", QTextFormat::Property::TableCellRightBorderBrush)
            .define_value("ImageName", QTextFormat::Property::ImageName)
            .define_value("ImageTitle", QTextFormat::Property::ImageTitle)
            .define_value("ImageAltText", QTextFormat::Property::ImageAltText)
            .define_value("ImageWidth", QTextFormat::Property::ImageWidth)
            .define_value("ImageHeight", QTextFormat::Property::ImageHeight)
            .define_value("ImageQuality", QTextFormat::Property::ImageQuality)
            .define_value("ImageMaxWidth", QTextFormat::Property::ImageMaxWidth)
            .define_value("FullWidthSelection", QTextFormat::Property::FullWidthSelection)
            .define_value("PageBreakPolicy", QTextFormat::Property::PageBreakPolicy)
            .define_value("UserProperty", QTextFormat::Property::UserProperty);

    Enum<QTextFormat::ObjectTypes> rb_cQTextFormatObjectTypes =
        // RubyQt6::QtGui::QTextFormat::ObjectTypes
        define_qenum_under<QTextFormat::ObjectTypes>("ObjectTypes", rb_cQTextFormat)
            .define_value("NoObject", QTextFormat::ObjectTypes::NoObject)
            .define_value("ImageObject", QTextFormat::ObjectTypes::ImageObject)
            .define_value("TableObject", QTextFormat::ObjectTypes::TableObject)
            .define_value("TableCellObject", QTextFormat::ObjectTypes::TableCellObject)
            .define_value("UserObject", QTextFormat::ObjectTypes::UserObject);

    Enum<QTextFormat::PageBreakFlag> rb_cQTextFormatPageBreakFlag =
        // RubyQt6::QtGui::QTextFormat::PageBreakFlag
        define_qenum_under<QTextFormat::PageBreakFlag>("PageBreakFlag", rb_cQTextFormat)
            .define_value("PageBreak_Auto", QTextFormat::PageBreakFlag::PageBreak_Auto)
            .define_value("PageBreak_AlwaysBefore", QTextFormat::PageBreakFlag::PageBreak_AlwaysBefore)
            .define_value("PageBreak_AlwaysAfter", QTextFormat::PageBreakFlag::PageBreak_AlwaysAfter);

    Data_Type<QFlags<QTextFormat::PageBreakFlag>> rb_cQTextFormatPageBreakFlags =
        // RubyQt6::QtGui::QTextFormat::PageBreakFlags
        define_qflags_under<QTextFormat::PageBreakFlag>(rb_cQTextFormat, "PageBreakFlags");

    rb_cQTextBlockFormat =
        // RubyQt6::QtGui::QTextBlockFormat
        define_class_under<QTextBlockFormat, QTextFormat>(rb_mQt6QtGui, "QTextBlockFormat")
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

    Enum<QTextBlockFormat::LineHeightTypes> rb_cQTextBlockFormatLineHeightTypes =
        // RubyQt6::QtGui::QTextBlockFormat::LineHeightTypes
        define_qenum_under<QTextBlockFormat::LineHeightTypes>("LineHeightTypes", rb_cQTextBlockFormat)
            .define_value("SingleHeight", QTextBlockFormat::LineHeightTypes::SingleHeight)
            .define_value("ProportionalHeight", QTextBlockFormat::LineHeightTypes::ProportionalHeight)
            .define_value("FixedHeight", QTextBlockFormat::LineHeightTypes::FixedHeight)
            .define_value("MinimumHeight", QTextBlockFormat::LineHeightTypes::MinimumHeight)
            .define_value("LineDistanceHeight", QTextBlockFormat::LineHeightTypes::LineDistanceHeight);

    Enum<QTextBlockFormat::MarkerType> rb_cQTextBlockFormatMarkerType =
        // RubyQt6::QtGui::QTextBlockFormat::MarkerType
        define_qenum_under<QTextBlockFormat::MarkerType>("MarkerType", rb_cQTextBlockFormat)
            .define_value("NoMarker", QTextBlockFormat::MarkerType::NoMarker)
            .define_value("Unchecked", QTextBlockFormat::MarkerType::Unchecked)
            .define_value("Checked", QTextBlockFormat::MarkerType::Checked);

    rb_cQTextCharFormat =
        // RubyQt6::QtGui::QTextCharFormat
        define_class_under<QTextCharFormat, QTextFormat>(rb_mQt6QtGui, "QTextCharFormat")
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

   Enum<QTextCharFormat::VerticalAlignment> rb_cQTextCharFormatVerticalAlignment =
        // RubyQt6::QtGui::QTextCharFormat::VerticalAlignment
        define_qenum_under<QTextCharFormat::VerticalAlignment>("VerticalAlignment", rb_cQTextCharFormat)
            .define_value("AlignNormal", QTextCharFormat::VerticalAlignment::AlignNormal)
            .define_value("AlignSuperScript", QTextCharFormat::VerticalAlignment::AlignSuperScript)
            .define_value("AlignSubScript", QTextCharFormat::VerticalAlignment::AlignSubScript)
            .define_value("AlignMiddle", QTextCharFormat::VerticalAlignment::AlignMiddle)
            .define_value("AlignTop", QTextCharFormat::VerticalAlignment::AlignTop)
            .define_value("AlignBottom", QTextCharFormat::VerticalAlignment::AlignBottom)
            .define_value("AlignBaseline", QTextCharFormat::VerticalAlignment::AlignBaseline);

    Enum<QTextCharFormat::UnderlineStyle> rb_cQTextCharFormatUnderlineStyle =
        // RubyQt6::QtGui::QTextCharFormat::UnderlineStyle
        define_qenum_under<QTextCharFormat::UnderlineStyle>("UnderlineStyle", rb_cQTextCharFormat)
            .define_value("NoUnderline", QTextCharFormat::UnderlineStyle::NoUnderline)
            .define_value("SingleUnderline", QTextCharFormat::UnderlineStyle::SingleUnderline)
            .define_value("DashUnderline", QTextCharFormat::UnderlineStyle::DashUnderline)
            .define_value("DotLine", QTextCharFormat::UnderlineStyle::DotLine)
            .define_value("DashDotLine", QTextCharFormat::UnderlineStyle::DashDotLine)
            .define_value("DashDotDotLine", QTextCharFormat::UnderlineStyle::DashDotDotLine)
            .define_value("WaveUnderline", QTextCharFormat::UnderlineStyle::WaveUnderline)
            .define_value("SpellCheckUnderline", QTextCharFormat::UnderlineStyle::SpellCheckUnderline);

    Enum<QTextCharFormat::FontPropertiesInheritanceBehavior> rb_cQTextCharFormatFontPropertiesInheritanceBehavior =
        // RubyQt6::QtGui::QTextCharFormat::FontPropertiesInheritanceBehavior
        define_qenum_under<QTextCharFormat::FontPropertiesInheritanceBehavior>("FontPropertiesInheritanceBehavior", rb_cQTextCharFormat)
            .define_value("FontPropertiesSpecifiedOnly", QTextCharFormat::FontPropertiesInheritanceBehavior::FontPropertiesSpecifiedOnly)
            .define_value("FontPropertiesAll", QTextCharFormat::FontPropertiesInheritanceBehavior::FontPropertiesAll);

    rb_cQTextImageFormat =
        // RubyQt6::QtGui::QTextImageFormat
        define_class_under<QTextImageFormat, QTextCharFormat>(rb_mQt6QtGui, "QTextImageFormat")
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
        define_class_under<QTextTableCellFormat, QTextCharFormat>(rb_mQt6QtGui, "QTextTableCellFormat")
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
        define_class_under<QTextFrameFormat, QTextFormat>(rb_mQt6QtGui, "QTextFrameFormat")
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

    Enum<QTextFrameFormat::Position> rb_cQTextFrameFormatPosition =
        // RubyQt6::QtGui::QTextFrameFormat::Position
        define_qenum_under<QTextFrameFormat::Position>("Position", rb_cQTextFrameFormat)
            .define_value("InFlow", QTextFrameFormat::Position::InFlow)
            .define_value("FloatLeft", QTextFrameFormat::Position::FloatLeft)
            .define_value("FloatRight", QTextFrameFormat::Position::FloatRight);

    Enum<QTextFrameFormat::BorderStyle> rb_cQTextFrameFormatBorderStyle =
        // RubyQt6::QtGui::QTextFrameFormat::BorderStyle
        define_qenum_under<QTextFrameFormat::BorderStyle>("BorderStyle", rb_cQTextFrameFormat)
            .define_value("BorderStyle_None", QTextFrameFormat::BorderStyle::BorderStyle_None)
            .define_value("BorderStyle_Dotted", QTextFrameFormat::BorderStyle::BorderStyle_Dotted)
            .define_value("BorderStyle_Dashed", QTextFrameFormat::BorderStyle::BorderStyle_Dashed)
            .define_value("BorderStyle_Solid", QTextFrameFormat::BorderStyle::BorderStyle_Solid)
            .define_value("BorderStyle_Double", QTextFrameFormat::BorderStyle::BorderStyle_Double)
            .define_value("BorderStyle_DotDash", QTextFrameFormat::BorderStyle::BorderStyle_DotDash)
            .define_value("BorderStyle_DotDotDash", QTextFrameFormat::BorderStyle::BorderStyle_DotDotDash)
            .define_value("BorderStyle_Groove", QTextFrameFormat::BorderStyle::BorderStyle_Groove)
            .define_value("BorderStyle_Ridge", QTextFrameFormat::BorderStyle::BorderStyle_Ridge)
            .define_value("BorderStyle_Inset", QTextFrameFormat::BorderStyle::BorderStyle_Inset)
            .define_value("BorderStyle_Outset", QTextFrameFormat::BorderStyle::BorderStyle_Outset);

    rb_cQTextTableFormat =
        // RubyQt6::QtGui::QTextTableFormat
        define_class_under<QTextTableFormat, QTextFrameFormat>(rb_mQt6QtGui, "QTextTableFormat")
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
            .define_method("set_column_width_constraints", &QTextTableFormat::setColumnWidthConstraints, Arg("constraints"))
            .define_method("set_columns", &QTextTableFormat::setColumns, Arg("columns"))
            .define_method("set_header_row_count", &QTextTableFormat::setHeaderRowCount, Arg("count"));

    rb_cQTextListFormat =
        // RubyQt6::QtGui::QTextListFormat
        define_class_under<QTextListFormat, QTextFormat>(rb_mQt6QtGui, "QTextListFormat")
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

    Enum<QTextListFormat::Style> rb_cQTextListFormatStyle =
        // RubyQt6::QtGui::QTextListFormat::Style
        define_qenum_under<QTextListFormat::Style>("Style", rb_cQTextListFormat)
            .define_value("ListDisc", QTextListFormat::Style::ListDisc)
            .define_value("ListCircle", QTextListFormat::Style::ListCircle)
            .define_value("ListSquare", QTextListFormat::Style::ListSquare)
            .define_value("ListDecimal", QTextListFormat::Style::ListDecimal)
            .define_value("ListLowerAlpha", QTextListFormat::Style::ListLowerAlpha)
            .define_value("ListUpperAlpha", QTextListFormat::Style::ListUpperAlpha)
            .define_value("ListLowerRoman", QTextListFormat::Style::ListLowerRoman)
            .define_value("ListUpperRoman", QTextListFormat::Style::ListUpperRoman)
            .define_value("ListStyleUndefined", QTextListFormat::Style::ListStyleUndefined);
}

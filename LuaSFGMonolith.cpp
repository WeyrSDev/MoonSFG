#include <SFGUI/SFGUI.hpp>
#include "LuaSFGMonolith.hpp"
#include <lua.hpp>

namespace ee {

int Adjustment_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::Adjustment>(L, 1));
    return 1; //return obj ptr
}

int Adjustment_gc(lua_State * L)
{
    killPtr<sfg::Adjustment>(L, 1);
    return 0;
}

int Adjustment_Create(lua_State * L)
{
    auto a = putPtr<sfg::Adjustment>(L, sfg::Adjustment::Create
    (
    luaL_optnumber(L, 1, 0.0), luaL_optnumber(L, 2, 0.0), luaL_optnumber(L, 3, 0.0),
    luaL_optnumber(L, 4, 1.0), luaL_optnumber(L, 5, 5.0), luaL_optnumber(L, 6, 0.0)
    ));
    return 1; //return ptr
}

int Adjustment_GetValue(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::Adjustment>(L, 1)->GetValue());
    return 1;
}

int Adjustment_SetValue(lua_State * L)
{
    getPtr<sfg::Adjustment>(L, 1)->SetValue(luaL_checknumber(L, 2));
    return 0;
}

int Adjustment_GetLower(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::Adjustment>(L, 1)->GetLower());
    return 1;
}

int Adjustment_SetLower(lua_State * L)
{
    getPtr<sfg::Adjustment>(L, 1)->SetLower(luaL_checknumber(L, 2));
    return 0;
}

int Adjustment_GetUpper(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::Adjustment>(L, 1)->GetUpper());
    return 1;
}

int Adjustment_SetUpper(lua_State * L)
{
    getPtr<sfg::Adjustment>(L, 1)->SetUpper(luaL_checknumber(L, 2));
    return 0;
}

int Adjustment_GetMinorStep(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::Adjustment>(L, 1)->GetMinorStep());
    return 1;
}

int Adjustment_SetMinorStep(lua_State * L)
{
    getPtr<sfg::Adjustment>(L, 1)->SetMinorStep(luaL_checknumber(L, 2));
    return 0;
}

int Adjustment_GetMajorStep(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::Adjustment>(L, 1)->GetMajorStep());
    return 1;
}

int Adjustment_SetMajorStep(lua_State * L)
{
    getPtr<sfg::Adjustment>(L, 1)->SetMajorStep(luaL_checknumber(L, 2));
    return 0;
}

int Adjustment_GetPageSize(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::Adjustment>(L, 1)->GetPageSize());
    return 1;
}

int Adjustment_SetPageSize(lua_State * L)
{
    getPtr<sfg::Adjustment>(L, 1)->SetPageSize(luaL_checknumber(L, 2));
    return 0;
}

int Adjustment_Configure(lua_State * L)
{
    getPtr<sfg::Adjustment>(L, 1)->Configure(
    luaL_checknumber(L, 2), luaL_checknumber(L, 3), luaL_checknumber(L, 4),
    luaL_checknumber(L, 5), luaL_checknumber(L, 6), luaL_checknumber(L, 7)
    );
    return 0;
}

int Adjustment_Increment(lua_State * L)
{
    getPtr<sfg::Adjustment>(L, 1)->Increment();
    return 0;
}

int Adjustment_Decrement(lua_State * L)
{
    getPtr<sfg::Adjustment>(L, 1)->Decrement();
    return 0;
}

int Adjustment_IncrementPage(lua_State * L)
{
    getPtr<sfg::Adjustment>(L, 1)->IncrementPage();
    return 0;
}

int Adjustment_DecrementPage(lua_State * L)
{
    getPtr<sfg::Adjustment>(L, 1)->DecrementPage();
    return 0;
}

const luaL_Reg AdjustmentReg[] = {
    { "Object", &Adjustment_Object},
    { "__gc", &Adjustment_gc},
    { "Create", &Adjustment_Create},
    { "GetValue", &Adjustment_GetValue},
    { "SetValue", &Adjustment_SetValue},
    { "GetLower", &Adjustment_GetLower},
    { "SetLower", &Adjustment_SetLower},
    { "GetUpper", &Adjustment_GetUpper},
    { "SetUpper", &Adjustment_SetUpper},
    { "GetMinorStep", &Adjustment_GetMinorStep},
    { "SetMinorStep", &Adjustment_SetMinorStep},
    { "GetMajorStep", &Adjustment_GetMajorStep},
    { "SetMajorStep", &Adjustment_SetMajorStep},
    { "GetPageSize", &Adjustment_GetPageSize},
    { "SetPageSize", &Adjustment_SetPageSize},
    { "Configure", &Adjustment_Configure},
    { "Increment", &Adjustment_Increment},
    { "Decrement", &Adjustment_Decrement},
    { "IncrementPage", &Adjustment_IncrementPage},
    { "DecrementPage", &Adjustment_DecrementPage},
    {nullptr, nullptr}
};

int openSFGAdjustment(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Adjustment>::get());
    luaL_setfuncs(L, AdjustmentReg, 0);
    indexize(L, -1);

    putSignalId(L, sfg::Adjustment::OnChange);
    lua_setfield(L, -2, "OnChange");

    lua_setglobal(L, Name<sfg::Adjustment>::get());
    return 1;
}

}

namespace ee {

int Alignment_Bin(lua_State * L)
{
    putPtr<sfg::Bin>(L, getPtr<sfg::Alignment>(L, 1));
    return 1;
}

int Alignment_Container(lua_State * L)
{
    putPtr<sfg::Container>(L, getPtr<sfg::Alignment>(L, 1));
    return 1;
}

int Alignment_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Alignment>(L, 1));
    return 1;
}

int Alignment_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::Alignment>(L, 1));
    return 1;
}

int Alignment_gc(lua_State * L)
{
    killPtr<sfg::Alignment>(L, 1);
    return 0;
}

int Alignment_Create(lua_State * L)
{
    putPtr<sfg::Alignment>(L, sfg::Alignment::Create());
    return 1;
}

int Alignment_SetScale(lua_State * L)
{
    getPtr<sfg::Alignment>(L, 1)->SetScale(sf::Vector2f(luaL_checknumber(L, 2), luaL_checknumber(L, 3)));
    return 0;
}

int Alignment_GetScale(lua_State * L)
{
    auto s = getPtr<sfg::Alignment>(L, 1)->GetScale();
    lua_pushnumber(L, s.x);
    lua_pushnumber(L, s.y);
    return 2;
}

int Alignment_SetAlignment(lua_State * L)
{
    getPtr<sfg::Alignment>(L, 1)->SetAlignment(sf::Vector2f(luaL_checknumber(L, 2), luaL_checknumber(L, 3)));
    return 0;
}

int Alignment_GetAlignment(lua_State * L)
{
    auto s = getPtr<sfg::Alignment>(L, 1)->GetAlignment();
    lua_pushnumber(L, s.x);
    lua_pushnumber(L, s.y);
    return 2;
}

const luaL_Reg AlignmentReg[] = {
    { "Bin", &Alignment_Bin},
    { "Container", &Alignment_Container},
    { "Widget", &Alignment_Widget},
    { "Object", &Alignment_Object},
    { "__gc", &Alignment_gc},
    { "Create", &Alignment_Create},
    { "SetScale", &Alignment_SetScale},
    { "GetScale", &Alignment_GetScale},
    { "SetAlignment", &Alignment_SetAlignment},
    { "GetAlignment", &Alignment_GetAlignment},
    {nullptr, nullptr}
};

int openSFGAlignment(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Alignment>::get());
    luaL_setfuncs(L, AlignmentReg, 0);
    indexize(L, -1);
    lua_setglobal(L, Name<sfg::Alignment>::get());
    return 1;
}

}

namespace ee {

int Bin_Container(lua_State * L)
{
    putPtr<sfg::Container>(L, getPtr<sfg::Bin>(L, 1));
    return 1;
}

int Bin_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Bin>(L, 1));
    return 1;
}

int Bin_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::Bin>(L, 1));
    return 1;
}

int Bin_gc(lua_State * L)
{
    killPtr<sfg::Bin>(L, 1);
    return 0;
}

int Bin_GetChild(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Bin>(L, 1)->GetChild());
    return 1;
}

const luaL_Reg BinReg[] = {
    { "Container", &Bin_Container},
    { "Widget", &Bin_Widget},
    { "Object", &Bin_Object},
    { "__gc", &Bin_gc},
    { "GetChild", &Bin_GetChild},
    {nullptr, nullptr}
};

int openSFGBin(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Bin>::get());
    luaL_setfuncs(L, BinReg, 0);
    indexize(L, -1);
    lua_setglobal(L, Name<sfg::Bin>::get());
    return 1;
}

}

namespace ee {

int Box_Container(lua_State * L)
{
    putPtr<sfg::Container>(L, getPtr<sfg::Box>(L, 1));
    return 1;
}

int Box_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Box>(L, 1));
    return 1;
}

int Box_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::Box>(L, 1));
    return 1;
}

int Box_gc(lua_State * L)
{
    killPtr<sfg::Box>(L, 1);
    return 0;
}

const char * const BoxOrientation[] = {
    "HORIZONTAL", "VERTICAL", nullptr
};

int Box_Create(lua_State * L)
{
    putPtr<sfg::Box>(L,
    sfg::Box::Create(
    static_cast<sfg::Box::Orientation> (luaL_checkoption(L, 1, "HORIZONTAL", BoxOrientation)),
    luaL_optnumber(L, 2, 0.0)
    ));
    return 1;
}

int Box_PackStart(lua_State * L)
{
    getPtr<sfg::Box>(L, 1)->PackStart(getPtr<sfg::Widget>(L, 2),
    optbool(L, 3, true), optbool(L, 4, true));
    return 0;
}

int Box_PackEnd(lua_State * L)
{
    getPtr<sfg::Box>(L, 1)->PackEnd(getPtr<sfg::Widget>(L, 2),
    optbool(L, 3, true), optbool(L, 4, true));
    return 0;
}

int Box_ReorderChild(lua_State * L)
{
    getPtr<sfg::Box>(L, 1)->ReorderChild(getPtr<sfg::Widget>(L, 2), luaL_checkunsigned(L, 3));
    return 0;
}

int Box_SetSpacing(lua_State * L)
{
    getPtr<sfg::Box>(L, 1)->SetSpacing(luaL_checknumber(L, 2));
    return 0;
}

int Box_GetSpacing(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::Box>(L, 1)->GetSpacing());
    return 1;
}

const luaL_Reg BoxReg[] = {

    { "Container", &Box_Container},
    { "Widget", &Box_Widget},
    { "Object", &Box_Object},
    { "__gc", &Box_gc},
    { "Create", &Box_Create},
    { "PackEnd", &Box_PackEnd},
    { "Pack", &Box_PackEnd}, //just as docs say - it's alias
    { "PackStart", &Box_PackStart},
    { "PackEnd", &Box_PackEnd},
    { "ReorderChild", &Box_ReorderChild},
    { "SetSpacing", &Box_SetSpacing},
    { "GetSpacing", &Box_GetSpacing},
    {nullptr, nullptr}
};

int openSFGBox(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Box>::get());
    luaL_setfuncs(L, BoxReg, 0);
    indexize(L, -1);
    lua_setglobal(L, Name<sfg::Box>::get());
    return 1;
}

}

namespace ee {

int Button_Bin(lua_State * L)
{
    putPtr<sfg::Bin>(L, getPtr<sfg::Button>(L, 1));
    return 1;
}

int Button_Container(lua_State * L)
{
    putPtr<sfg::Container>(L, getPtr<sfg::Button>(L, 1));
    return 1;
}

int Button_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Button>(L, 1));
    return 1;
}

int Button_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::Button>(L, 1));
    return 1;
}

int Button_gc(lua_State * L)
{
    killPtr<sfg::Button>(L, 1);
    return 0;
}

int Button_Create(lua_State * L)
{
    putPtr<sfg::Button>(L, sfg::Button::Create(luaL_optstring(L, 1, "")));
    return 1;
}

int Button_SetLabel(lua_State * L)
{
    getPtr<sfg::Button>(L, 1)->SetLabel(luaL_checkstring(L, 2));
    return 0;
}

int Button_GetLabel(lua_State * L)
{
    lua_pushstring(L, getPtr<sfg::Button>(L, 1)->GetLabel().toAnsiString().c_str());
    return 1;
}

int Button_SetImage(lua_State * L)
{
    getPtr<sfg::Button>(L, 1)->SetImage(getPtr<sfg::Image>(L, 2));
    return 0;
}

int Button_GetImage(lua_State * L)
{
    putPtr<sfg::Image>(L, getPtr<sfg::Button>(L, 1)->GetImage());
    return 1;
}

int Button_ClearImage(lua_State * L)
{
    getPtr<sfg::Button>(L, 1)->ClearImage();
    return 0;
}

const luaL_Reg ButtonReg[] = {
    { "Bin", &Button_Bin},
    { "Container", &Button_Container},
    { "Widget", &Button_Widget},
    { "Object", &Button_Object},
    { "__gc", &Button_gc},
    { "Create", &Button_Create},
    { "SetLabel", &Button_SetLabel},
    { "GetLabel", &Button_GetLabel},
    { "SetImage", &Button_SetImage},
    { "GetImage", &Button_GetImage},
    { "ClearImage", &Button_ClearImage},
    {nullptr, nullptr}
};

int openSFGButton(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Button>::get());
    luaL_setfuncs(L, ButtonReg, 0);
    indexize(L, -1);
    lua_setglobal(L, Name<sfg::Button>::get());
    return 1;
}

}

namespace ee {

int CheckButton_ToggleButton(lua_State * L)
{
    putPtr<sfg::ToggleButton>(L, getPtr<sfg::CheckButton>(L, 1));
    return 1;
}

int CheckButton_Button(lua_State * L)
{
    putPtr<sfg::Button>(L, getPtr<sfg::CheckButton>(L, 1));
    return 1;
}

int CheckButton_Bin(lua_State * L)
{
    putPtr<sfg::Bin>(L, getPtr<sfg::CheckButton>(L, 1));
    return 1;
}

int CheckButton_Container(lua_State * L)
{
    putPtr<sfg::Container>(L, getPtr<sfg::CheckButton>(L, 1));
    return 1;
}

int CheckButton_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::CheckButton>(L, 1));
    return 1;
}

int CheckButton_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::CheckButton>(L, 1));
    return 1;
}

int CheckButton_gc(lua_State * L)
{
    killPtr<sfg::CheckButton>(L, 1);
    return 0;
}

int CheckButton_Create(lua_State * L)
{
    putPtr<sfg::CheckButton>(L, sfg::CheckButton::Create(luaL_checkstring(L, 1)));
    return 1;
}

const luaL_Reg CheckButtonReg[] = {
    { "ToggleButton", &CheckButton_ToggleButton},
    { "Button", &CheckButton_Button},
    { "Bin", &CheckButton_Bin},
    { "Container", &CheckButton_Container},
    { "Widget", &CheckButton_Widget},
    { "Object", &CheckButton_Object},
    { "__gc", &CheckButton_gc},
    { "Create", &CheckButton_Create},
    {nullptr, nullptr}
};

int openSFGCheckButton(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::CheckButton>::get());
    luaL_setfuncs(L, CheckButtonReg, 0);
    indexize(L, -1);
    lua_setglobal(L, Name<sfg::CheckButton>::get());
    return 1;
}

}


namespace ee {

int ComboBox_Bin(lua_State * L)
{
    putPtr<sfg::Bin>(L, getPtr<sfg::ComboBox>(L, 1));
    return 1;
}

int ComboBox_Container(lua_State * L)
{
    putPtr<sfg::Container>(L, getPtr<sfg::ComboBox>(L, 1));
    return 1;
}

int ComboBox_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::ComboBox>(L, 1));
    return 1;
}

int ComboBox_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::ComboBox>(L, 1));
    return 1;
}

int ComboBox_gc(lua_State * L)
{
    killPtr<sfg::ComboBox>(L, 1);
    return 0;
}

int ComboBox_Create(lua_State * L)
{
    putPtr<sfg::ComboBox>(L, sfg::ComboBox::Create());
    return 1;
}

int ComboBox_GetSelectedItem(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::ComboBox>(L, 1)->GetSelectedItem());
    return 1;
}

int ComboBox_GetHighlightedItem(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::ComboBox>(L, 1)->GetHighlightedItem());
    return 1;
}

int ComboBox_SelectItem(lua_State * L)
{
    getPtr<sfg::ComboBox>(L, 1)->SelectItem(luaL_checknumber(L, 2));
    return 0;
}

int ComboBox_AppendItem(lua_State * L)
{
    getPtr<sfg::ComboBox>(L, 1)->AppendItem(luaL_checkstring(L, 2));
    return 0;
}

int ComboBox_InsertItem(lua_State * L)
{
    getPtr<sfg::ComboBox>(L, 1)->InsertItem(luaL_checknumber(L, 2), luaL_checkstring(L, 3));
    return 0;
}

int ComboBox_PrependItem(lua_State * L)
{
    getPtr<sfg::ComboBox>(L, 1)->PrependItem(luaL_checkstring(L, 2));
    return 0;
}

int ComboBox_ChangeItem(lua_State * L)
{
    getPtr<sfg::ComboBox>(L, 1)->ChangeItem(luaL_checknumber(L, 2), luaL_checkstring(L, 3));
    return 0;
}

int ComboBox_RemoveItem(lua_State * L)
{
    getPtr<sfg::ComboBox>(L, 1)->RemoveItem(luaL_checknumber(L, 2));
    return 0;
}

int ComboBox_GetSelectedText(lua_State * L)
{
    lua_pushstring(L, getPtr<sfg::ComboBox>(L, 1)->GetSelectedText().toAnsiString().c_str());
    return 1;
}

int ComboBox_GetItemCount(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::ComboBox>(L, 1)->GetItemCount());
    return 1;
}

int ComboBox_GetDisplayedItems(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::ComboBox>(L, 1)->GetDisplayedItems());
    return 1;
}

int ComboBox_GetStartItemIndex(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::ComboBox>(L, 1)->GetStartItemIndex());
    return 1;
}

int ComboBox_GetItem(lua_State * L)
{
    lua_pushstring(L, getPtr<sfg::ComboBox>(L, 1)->
    GetItem(luaL_checknumber(L, 2)).toAnsiString().c_str());
    return 1;
}

int ComboBox_IsPoppedUp(lua_State * L)
{
    lua_pushboolean(L, getPtr<sfg::ComboBox>(L, 1)->IsPoppedUp());
    return 1;
}

const luaL_Reg ComboBoxReg[] = {
    { "Bin", &ComboBox_Bin},
    { "Container", &ComboBox_Container},
    { "Widget", &ComboBox_Widget},
    { "Object", &ComboBox_Object},
    { "__gc", &ComboBox_gc},
    { "Create", &ComboBox_Create},
    { "GetSelectedItem", &ComboBox_GetSelectedItem},
    { "GetHighlightedItem", &ComboBox_GetHighlightedItem},
    { "SelectItem", &ComboBox_SelectItem},
    { "AppendItem", &ComboBox_AppendItem},
    { "InsertItem", &ComboBox_InsertItem},
    { "PrependItem", &ComboBox_PrependItem},
    { "ChangeItem", &ComboBox_ChangeItem},
    { "RemoveItem", &ComboBox_RemoveItem},
    { "GetSelectedText", &ComboBox_GetSelectedText},
    { "GetItemCount", &ComboBox_GetItemCount},
    { "GetDisplayedItems", &ComboBox_GetDisplayedItems},
    { "GetStartItemIndex", &ComboBox_GetStartItemIndex},
    { "GetItem", &ComboBox_GetItem},
    { "IsPoppedUp", &ComboBox_IsPoppedUp},
    {nullptr, nullptr}
};

int openSFGComboBox(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::ComboBox>::get());
    luaL_setfuncs(L, ComboBoxReg, 0);

    lua_pushnumber(L, sfg::ComboBox::NONE);
    lua_setfield(L, -2, "NONE");

    putSignalId(L, sfg::ComboBox::OnSelect);
    lua_setfield(L, -2, "OnSelect");
    putSignalId(L, sfg::ComboBox::OnOpen);
    lua_setfield(L, -2, "OnOpen");

    indexize(L, -1);
    lua_setglobal(L, Name<sfg::ComboBox>::get());
    return 1;
}

}

namespace ee {

int Container_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Container>(L, 1));
    return 1;
}

int Container_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::Container>(L, 1));
    return 1;
}

int Container_gc(lua_State * L)
{
    killPtr<sfg::Container>(L, 1);
    return 0;
}

int Container_Add(lua_State * L)
{
    getPtr<sfg::Container>(L, 1)->Add(getPtr<sfg::Widget>(L, 2));
    return 0;
}

int Container_Remove(lua_State * L)
{
    getPtr<sfg::Container>(L, 1)->Remove(getPtr<sfg::Widget>(L, 2));
    return 0;
}

int Container_RemoveAll(lua_State * L)
{
    getPtr<sfg::Container>(L, 1)->RemoveAll();
    return 0;
}

int Container_IsChild(lua_State * L)
{
    lua_pushboolean(L, getPtr<sfg::Container>(L, 1)->IsChild(getPtr<sfg::Widget>(L, 2)));
    return 1;
}

int Container_GetChildren(lua_State * L)
{
    auto c = getPtr<sfg::Container>(L, 1);

    lua_newtable(L);

    for (int i = 0; i < c->GetChildren().size(); ++i)
    {
        putPtr<sfg::Widget>(L, c->GetChildren()[i]);
        lua_rawseti(L, -2, i + 1);
    }

    return 1;
}

int Container_Refresh(lua_State * L)
{
    getPtr<sfg::Container>(L, 1)->Refresh();
    return 0;
}

const luaL_Reg ContainerReg[] = {
    { "Widget", &Container_Widget},
    { "Object", &Container_Object},
    { "__gc", &Container_gc},
    { "Add", &Container_Add},
    { "Remove", &Container_Remove},
    { "RemoveAll", &Container_RemoveAll},
    { "IsChild", &Container_IsChild},
    { "GetChildren", &Container_GetChildren},
    { "Refresh", &Container_Refresh},
    {nullptr, nullptr}
};

int openSFGContainer(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Container>::get());
    luaL_setfuncs(L, ContainerReg, 0);
    indexize(L, -1);
    lua_setglobal(L, Name<sfg::Container>::get());
    return 1;
}

}

namespace ee {

int Entry_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Entry>(L, 1));
    return 1;
}

int Entry_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::Entry>(L, 1));
    return 1;
}

int Entry_gc(lua_State * L)
{
    killPtr<sfg::Entry>(L, 1);
    return 0;
}

int Entry_Create(lua_State * L)
{
    putPtr<sfg::Entry>(L, sfg::Entry::Create(luaL_optstring(L, 2, "")));
    return 1;
}

int Entry_SetText(lua_State * L)
{
    getPtr<sfg::Entry>(L, 1)->SetText(luaL_checkstring(L, 2));
    return 0;
}

int Entry_GetText(lua_State * L)
{
    lua_pushstring(L, getPtr<sfg::Entry>(L, 1)->GetText().toAnsiString().c_str());
    return 1;
}

int Entry_AppendText(lua_State * L)
{
    getPtr<sfg::Entry>(L, 1)->AppendText(luaL_checkstring(L, 2));
    return 0;
}

int Entry_PrependText(lua_State * L)
{
    getPtr<sfg::Entry>(L, 1)->PrependText(luaL_checkstring(L, 2));
    return 0;
}

int Entry_GetVisibleText(lua_State * L)
{
    lua_pushstring(L, getPtr<sfg::Entry>(L, 1)->GetVisibleText().toAnsiString().c_str());
    return 1;
}

int Entry_GetVisibleOffset(lua_State * L)
{
    lua_pushunsigned(L, getPtr<sfg::Entry>(L, 1)->GetVisibleOffset());
    return 1;
}

int Entry_GetCursorPosition(lua_State * L)
{
    lua_pushunsigned(L, getPtr<sfg::Entry>(L, 1)->GetCursorPosition());
    return 1;
}

int Entry_SetCursorPosition(lua_State * L)
{
    getPtr<sfg::Entry>(L, 1)->SetCursorPosition(luaL_checknumber(L, 2));
    return 0;
}

int Entry_IsCursorVisible(lua_State * L)
{
    lua_pushboolean(L, getPtr<sfg::Entry>(L, 1)->IsCursorVisible());
    return 1;
}

int Entry_HideText(lua_State * L)
{
    getPtr<sfg::Entry>(L, 1)->HideText(luaL_checknumber(L, 2));
    return 0;
}

int Entry_GetHideCharacter(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::Entry>(L, 1)->GetHideCharacter());
    return 1;
}

int Entry_GetMaximumLength(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::Entry>(L, 1)->GetMaximumLength());
    return 1;
}

int Entry_SetMaximumLength(lua_State * L)
{
    getPtr<sfg::Entry>(L, 1)->SetMaximumLength(luaL_checknumber(L, 2));
    return 0;
}

const luaL_Reg EntryReg[] = {
    { "Widget", &Entry_Widget},
    { "Object", &Entry_Object},
    { "__gc", &Entry_gc},
    { "Create", &Entry_Create},
    { "SetText", &Entry_SetText},
    { "GetText", &Entry_GetText},
    { "AppendText", &Entry_AppendText},
    { "PrependText", &Entry_PrependText},
    { "GetVisibleText", &Entry_GetVisibleText},
    { "GetVisibleOffset", &Entry_GetVisibleOffset},
    { "GetCursorPosition", &Entry_GetCursorPosition},
    { "SetCursorPosition", &Entry_SetCursorPosition},
    { "IsCursorVisible", &Entry_IsCursorVisible},
    { "HideText", &Entry_HideText},
    { "GetHideCharacter", &Entry_GetHideCharacter},
    { "GetMaximumLength", &Entry_GetMaximumLength},
    { "SetMaximumLength", &Entry_SetMaximumLength},
    {nullptr, nullptr}
};

int openSFGEntry(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Entry>::get());
    luaL_setfuncs(L, EntryReg, 0);
    indexize(L, -1);

    putSignalId(L, sfg::Entry::OnTextChanged);
    lua_setfield(L, -2, "OnTextChanged");

    lua_setglobal(L, Name<sfg::Entry>::get());
    return 1;
}

}

namespace ee {

int Fixed_Container(lua_State * L)
{
    putPtr<sfg::Container>(L, getPtr<sfg::Fixed>(L, 1));
    return 1;
}

int Fixed_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Fixed>(L, 1));
    return 1;
}

int Fixed_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::Fixed>(L, 1));
    return 1;
}

int Fixed_gc(lua_State * L)
{
    killPtr<sfg::Fixed>(L, 1);
    return 0;
}

int Fixed_Put(lua_State * L)
{
    getPtr<sfg::Fixed>(L, 1)->Put(getPtr<sfg::Widget>(L, 2), sf::Vector2f(
    luaL_checknumber(L, 3), luaL_checknumber(L, 4)));
    return 0;
}

int Fixed_Move(lua_State * L)
{
    getPtr<sfg::Fixed>(L, 1)->Move(getPtr<sfg::Widget>(L, 2), sf::Vector2f(
    luaL_checknumber(L, 3), luaL_checknumber(L, 4)));
    return 0;
}

const luaL_Reg FixedReg[] = {
    { "Container", &Fixed_Container},
    { "Widget", &Fixed_Widget},
    { "Object", &Fixed_Object},
    { "__gc", &Fixed_gc},
    { "Put", &Fixed_Put},
    { "Move", &Fixed_Move},
    {nullptr, nullptr}
};

int openSFGFixed(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Fixed>::get());
    luaL_setfuncs(L, FixedReg, 0);
    indexize(L, -1);
    lua_setglobal(L, Name<sfg::Fixed>::get());
    return 1;
}

}

namespace ee {

int Frame_Bin(lua_State * L)
{
    putPtr<sfg::Bin>(L, getPtr<sfg::Frame>(L, 1));
    return 1;
}

int Frame_Container(lua_State * L)
{
    putPtr<sfg::Container>(L, getPtr<sfg::Frame>(L, 1));
    return 1;
}

int Frame_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Frame>(L, 1));
    return 1;
}

int Frame_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::Frame>(L, 1));
    return 1;
}

int Frame_gc(lua_State * L)
{
    killPtr<sfg::Frame>(L, 1);
    return 0;
}

int Frame_Create(lua_State * L)
{
    putPtr<sfg::Frame>(L, sfg::Frame::Create(luaL_optstring(L, 1, "")));
    return 1;
}

int Frame_SetLabel(lua_State * L)
{
    getPtr<sfg::Frame>(L, 1)->SetLabel(luaL_checkstring(L, 2));
    return 0;
}

int Frame_GetLabel(lua_State * L)
{
    lua_pushstring(L, getPtr<sfg::Frame>(L, 1)->GetLabel().toAnsiString().c_str());
    return 1;
}

int Frame_SetAlignment(lua_State * L)
{
    getPtr<sfg::Frame>(L, 1)->SetAlignment(sf::Vector2f(
    luaL_checknumber(L, 2), luaL_checknumber(L, 3)));
    return 0;
}

int Frame_GetAlignment(lua_State * L)
{
    sf::Vector2f v = getPtr<sfg::Frame>(L, 1)->GetAlignment();
    lua_pushnumber(L, v.x);
    lua_pushnumber(L, v.y);
    return 2;
}

const luaL_Reg FrameReg[] = {
    { "Bin", &Frame_Bin},
    { "Container", &Frame_Container},
    { "Widget", &Frame_Widget},
    { "Object", &Frame_Object},
    { "__gc", &Frame_gc},
    { "Create", &Frame_Create},
    { "SetLabel", &Frame_SetLabel},
    { "GetLabel", &Frame_GetLabel},
    { "SetAlignment", &Frame_SetAlignment},
    { "GetAlignment", &Frame_GetAlignment},
    {nullptr, nullptr}
};

int openSFGFrame(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Frame>::get());
    luaL_setfuncs(L, FrameReg, 0);
    indexize(L, -1);
    lua_setglobal(L, Name<sfg::Frame>::get());
    return 1;
}

}

namespace ee {

//from obj to any derieved
//and
//from widget to any derieved?

const luaL_Reg castReg[] = {

    {nullptr, nullptr}
};

int openSFGCasts(lua_State * L)
{
    lua_pushglobaltable(L);
    luaL_setfuncs(L, castReg, 0);
    lua_pop(L, 1);
    return 1;
}

}

namespace ee {

int Image_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Image>(L, 1));
    return 1;
}

int Image_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::Image>(L, 1));
    return 1;
}

int Image_gc(lua_State * L)
{
    killPtr<sfg::Image>(L, 1);
    return 0;
}

int Image_Create(lua_State * L)
{
    putPtr<sfg::Image>(L, sfg::Image::Create());
    return 1;
}

int Image_SetAlignment(lua_State * L)
{
    getPtr<sfg::Image>(L, 1)->SetAlignment(sf::Vector2f(
    luaL_checknumber(L, 2), luaL_checknumber(L, 3)));
    return 0;
}

int Image_GetAlignment(lua_State * L)
{
    sf::Vector2f v = getPtr<sfg::Image>(L, 1)->GetAlignment();
    lua_pushnumber(L, v.x);
    lua_pushnumber(L, v.y);
    return 2;
}

const luaL_Reg ImageReg[] = {
    { "Widget", &Image_Widget},
    { "Object", &Image_Object},
    { "__gc", &Image_gc},
    { "Create", &Image_Create},
    { "SetAlignment", &Image_SetAlignment},
    { "GetAlignment", &Image_GetAlignment},
    {nullptr, nullptr}
};

int openSFGImage(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Image>::get());
    luaL_setfuncs(L, ImageReg, 0);
    indexize(L, -1);
    lua_setglobal(L, Name<sfg::Image>::get());
    return 1;
}

}

namespace ee {

int Label_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Label>(L, 1));
    return 1;
}

int Label_gc(lua_State * L)
{
    killPtr<sfg::Label>(L, 1);
    return 0;
}

int Label_Create(lua_State * L)
{
    putPtr<sfg::Label>(L, sfg::Label::Create(luaL_optstring(L, 1, "")));
    return 1;
}

int Label_SetText(lua_State * L)
{
    getPtr<sfg::Label>(L, 1)->SetText(luaL_checkstring(L, 2));
    return 0;
}

int Label_GetText(lua_State * L)
{
    lua_pushstring(L, getPtr<sfg::Label>(L, 1)->GetText().toAnsiString().c_str());
    return 1;
}

int Label_SetLineWrap(lua_State * L)
{
    getPtr<sfg::Label>(L, 1)->SetLineWrap(checkbool(L, 2));
    return 0;
}

int Label_GetLineWrap(lua_State * L)
{
    lua_pushboolean(L, getPtr<sfg::Label>(L, 1)->GetLineWrap());
    return 1;
}

int Label_GetWrappedText(lua_State * L)
{
    lua_pushstring(L, getPtr<sfg::Label>(L, 1)->GetWrappedText().toAnsiString().c_str());
    return 1;
}

int Label_SetAlignment(lua_State * L)
{
    getPtr<sfg::Alignment>(L, 1)->SetAlignment(sf::Vector2f(luaL_checknumber(L, 2), luaL_checknumber(L, 3)));
    return 0;
}

int Label_GetAlignment(lua_State * L)
{
    auto s = getPtr<sfg::Alignment>(L, 1)->GetAlignment();
    lua_pushnumber(L, s.x);
    lua_pushnumber(L, s.y);
    return 2;
}

const luaL_Reg LabelReg[] = {
    { "Widget", &Label_Widget},
    { "__gc", &Label_gc},
    { "Create", &Label_Create},
    { "SetText", &Label_SetText},
    { "GetText", &Label_GetText},
    { "SetLineWrap", &Label_SetLineWrap},
    { "GetLineWrap", &Label_GetLineWrap},
    { "GetWrappedText", &Label_GetWrappedText},
    { "SetAlignment", &Label_SetAlignment},
    { "GetAlignment", &Label_GetAlignment},
    {nullptr, nullptr}
};

int openSFGLabel(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Label>::get());
    luaL_setfuncs(L, LabelReg, 0);
    indexize(L, -1);
    lua_setglobal(L, Name<sfg::Label>::get());
    return 1;
}

}

namespace ee {

int openLuaSFG(lua_State* L)
{
    openSFGObject(L); //must be first, for signal push support
    openSFGCasts(L);
    openSFGAdjustment(L);
    openSFGAlignment(L);
    openSFGBin(L);
    openSFGBox(L);
    openSFGButton(L);
    openSFGCheckButton(L);
    openSFGComboBox(L);
    openSFGContainer(L);
    openSFGEntry(L);
    openSFGFixed(L);
    openSFGFrame(L);
    openSFGImage(L);
    openSFGLabel(L);
    openSFGNotebook(L);
    openSFGProgressBar(L);
    openSFGRadioButton(L);
    openSFGRadioButtonGroup(L);
    openSFGRange(L);
    openSFGScale(L);
    openSFGScrollbar(L);
    openSFGScrolledWindow(L);
    //selector - not a widget lol
    openSFGSeparator(L);
    openSFGSpinButton(L);
    openSFGSpinner(L);
    openSFGTable(L);
    openSFGToggleButton(L);
    //viewport?????
    openSFGWidget(L);
    openSFGWindow(L);
    return 1;
}

}

namespace ee {

int Notebook_Container(lua_State * L)
{
    putPtr<sfg::Container>(L, getPtr<sfg::Notebook>(L, 1));
    return 1;
}

int Notebook_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Notebook>(L, 1));
    return 1;
}

int Notebook_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::Notebook>(L, 1));
    return 1;
}

int Notebook_gc(lua_State * L)
{
    killPtr<sfg::Notebook>(L, 1);
    return 0;
}

int Notebook_Create(lua_State * L)
{
    putPtr<sfg::Notebook>(L, sfg::Notebook::Create());
    return 1;
}

int Notebook_AppendPage(lua_State * L)
{
    auto c = getPtr<sfg::Widget>(L, 2);
    auto l = getPtr<sfg::Widget>(L, 3);
    lua_pushinteger(L, getPtr<sfg::Notebook>(L, 1)->AppendPage(c, l));
    return 1;
}

int Notebook_PrependPage(lua_State * L)
{
    auto c = getPtr<sfg::Widget>(L, 2);
    auto l = getPtr<sfg::Widget>(L, 3);
    lua_pushinteger(L, getPtr<sfg::Notebook>(L, 1)->PrependPage(c, l));
    return 1;
}

int Notebook_InsertPage(lua_State * L)
{
    auto c = getPtr<sfg::Widget>(L, 2);
    auto l = getPtr<sfg::Widget>(L, 3);
    sfg::Notebook::IndexType i = luaL_checknumber(L, 4);
    lua_pushinteger(L, getPtr<sfg::Notebook>(L, 1)->InsertPage(c, l, i));
    return 1;
}

int Notebook_RemovePage(lua_State * L)
{
    getPtr<sfg::Notebook>(L, 1)->RemovePage(luaL_checknumber(L, 2));
    return 0;
}

int Notebook_GetPageOf(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::Notebook>(L, 1)->GetPageOf(getPtr<sfg::Widget>(L, 2)));
    return 1;
}

int Notebook_NextPage(lua_State * L)
{
    getPtr<sfg::Notebook>(L, 1)->NextPage();
    return 0;
}

int Notebook_PreviousPage(lua_State * L)
{
    getPtr<sfg::Notebook>(L, 1)->PreviousPage();
    return 0;
}

int Notebook_ReorderChild(lua_State * L)
{
    getPtr<sfg::Notebook>(L, 1)->ReorderChild(getPtr<sfg::Widget>(L, 2), luaL_checknumber(L, 3));
    return 0;
}

int Notebook_GetTabPosition(lua_State * L)
{
    switch (getPtr<sfg::Notebook>(L, 1)->GetTabPosition())
    {
        case sfg::Notebook::TabPosition::TOP:
            lua_pushliteral(L, "TOP");
            break;
        case sfg::Notebook::TabPosition::BOTTOM:
            lua_pushliteral(L, "BOTTOM");
            break;
        case sfg::Notebook::TabPosition::LEFT:
            lua_pushliteral(L, "LEFT");
            break;
        case sfg::Notebook::TabPosition::RIGHT:
            lua_pushliteral(L, "RIGHT");
            break;
    }
    return 1;
}

const char * const NotebookTabPosition[] = {
    "TOP", "BOTTOM", "LEFT", "RIGHT", nullptr
};

int Notebook_SetTabPosition(lua_State * L)
{
    getPtr<sfg::Notebook>(L, 1)->SetTabPosition(static_cast<sfg::Notebook::TabPosition> (
    luaL_checkoption(L, 2, nullptr, NotebookTabPosition)));
    return 0;
}

int Notebook_GetCurrentPage(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::Notebook>(L, 1)->GetCurrentPage());
    return 1;
}

int Notebook_GetNthPage(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Notebook>(L, 1)->GetNthPage(luaL_checknumber(L, 2)));
    return 1;
}

int Notebook_GetNthLabel(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Notebook>(L, 1)->GetNthTabLabel(luaL_checknumber(L, 2)));
    return 1;
}

int Notebook_GetPageCount(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::Notebook>(L, 1)->GetPageCount());
    return 1;
}

int Notebook_GetTabLabel(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Notebook>(L, 1)->GetTabLabel(getPtr<sfg::Widget>(L, 2)));
    return 1;
}

int Notebook_SetTabLabel(lua_State * L)
{
    getPtr<sfg::Notebook>(L, 1)->SetTabLabel(getPtr<sfg::Widget>(L, 2), getPtr<sfg::Widget>(L, 3));
    return 0;
}

int Notebook_SetCurrentPage(lua_State * L)
{
    getPtr<sfg::Notebook>(L, 1)->SetCurrentPage(luaL_checknumber(L, 2));
    return 0;
}

int Notebook_GetPrelightTab(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::Notebook>(L, 1)->GetPrelightTab());
    return 1;
}

int Notebook_SetScrollable(lua_State * L)
{
    getPtr<sfg::Notebook>(L, 1)->SetScrollable(checkbool(L, 2));
    return 0;
}

int Notebook_GetScrollable(lua_State * L)
{
    lua_pushboolean(L, getPtr<sfg::Notebook>(L, 1)->GetScrollable());
    return 1;
}

int Notebook_GetFirstDisplayedTab(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::Notebook>(L, 1)->GetFirstDisplayedTab());
    return 1;
}

int Notebook_GetDisplayedTabCount(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::Notebook>(L, 1)->GetDisplayedTabCount());
    return 1;
}

int Notebook_IsScrollingForward(lua_State * L)
{
    lua_pushboolean(L, getPtr<sfg::Notebook>(L, 1)->IsScrollingForward());
    return 1;
}

int Notebook_IsScrollingBackward(lua_State * L)
{
    lua_pushboolean(L, getPtr<sfg::Notebook>(L, 1)->IsScrollingBackward());
    return 1;
}

int Notebook_IsForwardScrollPrelight(lua_State * L)
{
    lua_pushboolean(L, getPtr<sfg::Notebook>(L, 1)->IsForwardScrollPrelight());
    return 1;
}

int Notebook_IsBackwardScrollPrelight(lua_State * L)
{
    lua_pushboolean(L, getPtr<sfg::Notebook>(L, 1)->IsBackwardScrollPrelight());
    return 1;
}

const luaL_Reg NotebookReg[] = {
    { "Container", &Notebook_Container},
    { "Widget", &Notebook_Widget},
    { "Object", &Notebook_Object},
    { "__gc", &Notebook_gc},
    { "Create", &Notebook_Create},
    { "AppendPage", &Notebook_AppendPage},
    { "PrependPage", &Notebook_PrependPage},
    { "PrependPage", &Notebook_InsertPage},
    { "RemovePage", &Notebook_RemovePage},
    { "GetPageOf", &Notebook_GetPageOf},
    { "NextPage", &Notebook_NextPage},
    { "PreviousPage", &Notebook_PreviousPage},
    { "ReorderChild", &Notebook_ReorderChild},
    { "GetTabPosition", &Notebook_GetTabPosition},
    { "SetTabPosition", &Notebook_SetTabPosition},
    { "GetCurrentPage", &Notebook_GetCurrentPage},
    { "GetNthPage", &Notebook_GetNthPage},
    { "GetNthLabel", &Notebook_GetNthLabel},
    { "GetPageCount", &Notebook_GetPageCount},
    { "GetTabLabel", &Notebook_GetTabLabel},
    { "SetTabLabel", &Notebook_SetTabLabel},
    { "SetCurrentPage", &Notebook_SetCurrentPage},
    { "GetPrelightTab", &Notebook_GetPrelightTab},
    { "SetScrollable", &Notebook_SetScrollable},
    { "GetScrollable", &Notebook_GetScrollable},
    { "GetFirstDisplayedTab", &Notebook_GetFirstDisplayedTab},
    { "GetDisplayedTabCount", &Notebook_GetDisplayedTabCount},
    { "IsScrollingForward", &Notebook_IsScrollingForward},
    { "IsScrollingBackward", &Notebook_IsScrollingBackward},
    { "IsForwardScrollPrelight", &Notebook_IsForwardScrollPrelight},
    { "IsBackwardScrollPrelight", &Notebook_IsBackwardScrollPrelight},

    {nullptr, nullptr}
};

int openSFGNotebook(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Notebook>::get());
    luaL_setfuncs(L, NotebookReg, 0);
    indexize(L, -1);
    lua_setglobal(L, Name<sfg::Notebook>::get());
    return 1;
}

}

namespace ee {

static char StateLife = 0;

class LuaSignal
{

public:

    ~LuaSignal()
    {
        if (live.lock())
            luaL_unref(L, LUA_REGISTRYINDEX, f);
    }

    void invoke()
    {
        if (live.lock())
        {
            lua_rawgeti(L, LUA_REGISTRYINDEX, f);
            if (lua_pcall(L, 0, 0, 0))
            {
                sf::err() << lua_tostring(L, -1) << std::endl;
                lua_pop(L, 1);
            }
        }
    }

    int f;
    lua_State * L; //state, might be not valid..
    std::weak_ptr<bool> live; //value is trash, we care for locking

};

int Object_gc(lua_State * L)
{
    killPtr<sfg::Object>(L, 1);
    return 0;
}

void callLuaSignal(const std::shared_ptr<LuaSignal>& ls)
{
    ls->invoke();
}

int Object_Connect(lua_State * L)
{
    auto o = getPtr<sfg::Object>(L, 1);
    auto& s = getSignalId(L, 2);

    std::shared_ptr<LuaSignal> ls = std::make_shared<LuaSignal>();
    ls->L = L;
    ls->f = luaL_ref(L, LUA_REGISTRYINDEX);

    lua_pushlightuserdata(L, &StateLife);
    lua_gettable(L, LUA_REGISTRYINDEX);
    ls->live = *static_cast<std::shared_ptr<bool>*> (lua_touserdata(L, -1));
    lua_pop(L, 1);

    lua_pushnumber(L, o->GetSignal(s).Connect(std::bind(&callLuaSignal, ls)));

    return 1;
}

int Object_Disconnect(lua_State * L)
{
    auto o = getPtr<sfg::Object>(L, 1);
    auto& s = getSignalId(L, 2);
    o->GetSignal(s).Disconnect(luaL_checknumber(L, 3));
    return 0;
}

const luaL_Reg ObjectReg[] = {
    {"__gc", &Object_gc},
    {"Connect", & Object_Connect},
    {"Disconnect", &Object_Disconnect},
    {nullptr, nullptr}
};

int delPtr(lua_State * L)
{
    static_cast<std::shared_ptr<bool>*> (lua_touserdata(L, 1))->~shared_ptr();
    return 0;
}

int openSFGObject(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Object>::get());
    luaL_setfuncs(L, ObjectReg, 0);
    indexize(L, -1);
    lua_setglobal(L, Name<sfg::Object>::get());

    luaL_newmetatable(L, Name<sfg::Signal::SignalID>::get()); //for type recognition only
    lua_pop(L, 1);

    lua_pushlightuserdata(L, &StateLife);
    void * ud = lua_newuserdata(L, sizeof (std::shared_ptr<bool>));
    new(ud) std::shared_ptr<bool>(std::make_shared<bool>());

    lua_newtable(L);
    lua_pushcclosure(L, &delPtr, 0);
    lua_setfield(L, -2, "__gc");
    lua_setmetatable(L, -2);

    lua_settable(L, LUA_REGISTRYINDEX);

    return 1;
}

}

namespace ee {

int ProgressBar_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::ProgressBar>(L, 1));
    return 1;
}

int ProgressBar_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::ProgressBar>(L, 1));
    return 1;
}

int ProgressBar_gc(lua_State * L)
{
    killPtr<sfg::ProgressBar>(L, 1);
    return 0;
}

const char * const ProgressBarOrientation[] = {
    "HORIZONTAL", "VERTICAL", nullptr
};

int ProgressBar_Create(lua_State * L)
{
    putPtr<sfg::ProgressBar>(L, sfg::ProgressBar::Create(static_cast<sfg::ProgressBar::Orientation>
    (luaL_checkoption(L, 1, "HORIZONTAL", ProgressBarOrientation))));
    return 1;
}

int ProgressBar_SetOrientation(lua_State * L)
{
    getPtr<sfg::ProgressBar>(L, 1)->SetOrientation(static_cast<sfg::ProgressBar::Orientation> (
    luaL_checkoption(L, 2, nullptr, ProgressBarOrientation)));
    return 0;
}

int ProgressBar_GetOrientation(lua_State * L)
{
    lua_pushstring(L, ProgressBarOrientation[
    static_cast<int> (getPtr<sfg::ProgressBar>(L, 1)->GetOrientation())
    ]);
    return 1;
}

int ProgressBar_SetFraction(lua_State * L)
{
    getPtr<sfg::ProgressBar>(L, 1)->SetFraction(luaL_checknumber(L, 2));
    return 0;
}

int ProgressBar_GetFraction(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::ProgressBar>(L, 1)->GetFraction());
    return 1;
}

const luaL_Reg ProgressBarReg[] = {
    { "Widget", &ProgressBar_Widget},
    { "Object", &ProgressBar_Object},
    { "__gc", &ProgressBar_gc},
    { "Create", &ProgressBar_Create},
    { "SetOrientation", &ProgressBar_SetOrientation},
    { "GetOrientation", &ProgressBar_GetOrientation},
    { "SetFraction", &ProgressBar_SetFraction},
    { "GetFraction", &ProgressBar_GetFraction},
    {nullptr, nullptr}
};

int openSFGProgressBar(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::ProgressBar>::get());
    luaL_setfuncs(L, ProgressBarReg, 0);
    indexize(L, -1);
    lua_setglobal(L, Name<sfg::ProgressBar>::get());
    return 1;
}

}

namespace ee {

int RadioButton_CheckButton(lua_State * L)
{
    putPtr<sfg::CheckButton>(L, getPtr<sfg::RadioButton>(L, 1));
    return 1;
}

int RadioButton_ToggleButton(lua_State * L)
{
    putPtr<sfg::ToggleButton>(L, getPtr<sfg::RadioButton>(L, 1));
    return 1;
}

int RadioButton_Button(lua_State * L)
{
    putPtr<sfg::Button>(L, getPtr<sfg::RadioButton>(L, 1));
    return 1;
}

int RadioButton_Bin(lua_State * L)
{
    putPtr<sfg::Bin>(L, getPtr<sfg::RadioButton>(L, 1));
    return 1;
}

int RadioButton_Container(lua_State * L)
{
    putPtr<sfg::Container>(L, getPtr<sfg::RadioButton>(L, 1));
    return 1;
}

int RadioButton_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::RadioButton>(L, 1));
    return 1;
}

int RadioButton_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::RadioButton>(L, 1));
    return 1;
}

int RadioButton_gc(lua_State * L)
{
    killPtr<sfg::RadioButton>(L, 1);
    return 0;
}

int RadioButton_Create(lua_State * L)
{
    sfg::RadioButton::Ptr ptr;
    if (lua_gettop(L) > 1)
    {
        ptr = sfg::RadioButton::Create(luaL_checkstring(L, 1), getPtr<sfg::RadioButton::RadioButtonGroup>(L, 2));
    }
    else
    {
        ptr = sfg::RadioButton::Create(luaL_checkstring(L, 1));
    }
    putPtr<sfg::RadioButton>(L, ptr);
    return 1;
}

int RadioButton_GetGroup(lua_State * L)
{
    putPtr<sfg::RadioButton::RadioButtonGroup>(L, getPtr<sfg::RadioButton>(L, 1)->
    GetGroup());
    return 1;
}

int RadioButton_SetGroup(lua_State * L)
{
    getPtr<sfg::RadioButton>(L, 1)->SetGroup(getPtr<sfg::RadioButton::RadioButtonGroup>(L, 2));
    return 0;
}

const luaL_Reg RadioButtonReg[] = {
    { "CheckButton", &RadioButton_CheckButton},
    { "ToggleButton", &RadioButton_ToggleButton},
    { "Button", &RadioButton_Button},
    { "Bin", &RadioButton_Bin},
    { "Container", &RadioButton_Container},
    { "Widget", &RadioButton_Widget},
    { "Object", &RadioButton_Object},
    { "__gc", &RadioButton_gc},
    { "Create", &RadioButton_Create},
    { "GetGroup", &RadioButton_GetGroup},
    { "SetGroup", &RadioButton_SetGroup},
    {nullptr, nullptr}
};

int openSFGRadioButton(lua_State * L)
{


    return 1;
}

}

namespace ee {

int RadioButtonGroup_gc(lua_State * L)
{
    killPtr<sfg::RadioButton::RadioButtonGroup>(L, 1);
    return 0;
}

int RadioButtonGroup_Create(lua_State * L)
{

    return 1;
}

int RadioButtonGroup_GetMembers(lua_State * L)
{
    auto m = getPtr<sfg::RadioButton::RadioButtonGroup>(L, 1)->GetMembers();

    lua_newtable(L);

    int index = 1;

    for (auto& i : m)
    {
        if (auto ptr = i.lock())
        {
            putPtr<sfg::RadioButton>(L, ptr);
            lua_rawseti(L, -2, index);
            ++index;
        }
    }
    return 1;
}

const luaL_Reg RadioButtonGroupReg[] = {
    { "__gc", &RadioButtonGroup_gc},
    { "Create", &RadioButtonGroup_Create},
    { "GetMembers", &RadioButtonGroup_GetMembers},
    {nullptr, nullptr}
};

int openSFGRadioButtonGroup(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::RadioButton::RadioButtonGroup>::get());
    luaL_setfuncs(L, RadioButtonGroupReg, 0);
    indexize(L, -1);
    lua_setglobal(L, Name<sfg::RadioButton::RadioButtonGroup>::get());
    return 1;
}

}

namespace ee {

int Range_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Range>(L, 1));
    return 1;
}

int Range_Object(lua_State * L)
{
    putPtr<sfg::Object>(L,getPtr<sfg::Range>(L,1));
    return 1;
}

int Range_gc(lua_State * L)
{
    killPtr<sfg::Range>(L, 1);
    return 0;
}

const char * const RangeOrientation[] = {
    "HORIZONTAL", "VERTICAL", nullptr
};

int Range_GetAdjustment(lua_State * L)
{
    putPtr<sfg::Adjustment>(L, getPtr<sfg::Range>(L, 1)->GetAdjustment());
    return 1;
}

int Range_SetAdjustment(lua_State * L)
{
    getPtr<sfg::Range>(L, 1)->SetAdjustment(getPtr<sfg::Adjustment>(L, 2));
    return 0;
}

int Range_GetValue(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::Range>(L, 1)->GetValue());
    return 1;
}

int Range_SetValue(lua_State * L)
{
    getPtr<sfg::Range>(L, 1)->SetValue(luaL_checknumber(L, 2));
    return 0;
}

int Range_SetIncremenets(lua_State * L)
{
    getPtr<sfg::Range>(L, 1)->SetIncrements(luaL_checknumber(L, 2), luaL_checknumber(L, 3));
    return 0;
}

int Range_SetRange(lua_State * L)
{
    getPtr<sfg::Range>(L, 1)->SetRange(luaL_checknumber(L, 2), luaL_checknumber(L, 3));
    return 0;
}

int Range_GetOrientation(lua_State * L)
{
    lua_pushstring(L, RangeOrientation[static_cast<int> (getPtr<sfg::Range>(L, 1)->GetOrientation())]);
    return 1;
}

const luaL_Reg RangeReg[] = {
    { "Widget", &Range_Widget},
    { "__gc", &Range_gc},
    { "GetAdjustment", &Range_GetAdjustment},
    { "SetAdjustment", &Range_SetAdjustment},
    { "GetValue", &Range_GetValue},
    { "SetValue", &Range_SetValue},
    { "SetIncremenets", &Range_SetIncremenets},
    { "SetRange", &Range_SetRange},
    { "GetOrientation", &Range_GetOrientation},
    {nullptr, nullptr}
};

int openSFGRange(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Range>::get());
    luaL_setfuncs(L, RangeReg, 0);
    indexize(L, -1);
    lua_setglobal(L, Name<sfg::Range>::get());
    return 1;
}

}

namespace ee {

int Scale_Range(lua_State * L)
{
    putPtr<sfg::Range>(L, getPtr<sfg::Scale>(L, 1));
    return 1;
}

int Scale_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Scale>(L, 1));
    return 1;
}

int Scale_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::Scale>(L, 1));
    return 1;
}

int Scale_gc(lua_State * L)
{
    killPtr<sfg::Scale>(L, 1);
    return 0;
}

const char * const ScaleOrientation[] = {//should reuse from range? not for now..
    "HORIZONTAL", "VERTICAL", nullptr
};

int Scale_Create(lua_State * L)
{
    sfg::Scale::Ptr ptr;
    if (lua_gettop(L) > 1)
    {
        ptr = sfg::Scale::Create(
        luaL_checknumber(L, 1), luaL_checknumber(L, 2), luaL_checknumber(L, 3),
        static_cast<sfg::Scale::Orientation> (luaL_checkoption(L, 1, "HORIZONTAL", ScaleOrientation)));
    }
    else//0 or 1
    {
        ptr = sfg::Scale::Create(static_cast<sfg::Scale::Orientation> (
        luaL_checkoption(L, 1, "HORIZONTAL", ScaleOrientation)));
    }
    putPtr<sfg::Scale>(L, ptr);
    return 1;
}

int Scale_GetSliderRect(lua_State * L)
{
    const sf::FloatRect r = getPtr<sfg::Scale>(L, 1)->GetSliderRect();

    lua_pushnumber(L, r.left);
    lua_pushnumber(L, r.top);
    lua_pushnumber(L, r.width);
    lua_pushnumber(L, r.height);

    return 4;
}

const luaL_Reg ScaleReg[] = {
    { "Range", &Scale_Range},
    { "Widget", &Scale_Widget},
    { "Object", &Scale_Object},
    { "__gc", &Scale_gc},
    { "Create", &Scale_Create},
    { "GetSliderRect", &Scale_GetSliderRect},
    {nullptr, nullptr}
};

int openSFGScale(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Scale>::get());
    luaL_setfuncs(L, ScaleReg, 0);
    indexize(L, -1);
    lua_setglobal(L, Name<sfg::Scale>::get());
    return 1;
}

}

namespace ee {

int Scrollbar_Range(lua_State * L)
{
    putPtr<sfg::Range>(L, getPtr<sfg::Scrollbar>(L, 1));
    return 1;
}

int Scrollbar_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Scrollbar>(L, 1));
    return 1;
}

int Scrollbar_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::Scrollbar>(L, 1));
    return 1;
}

int Scrollbar_gc(lua_State * L)
{
    killPtr<sfg::Scrollbar>(L, 1);
    return 0;
}

const char * const ScrollbarOrientation[] = {//same as scale comment
    "HORIZONTAL", "VERTICAL", nullptr
};

int Scrollbar_Create(lua_State * L)
{
    sfg::Scrollbar::Ptr ptr;
    if (lua_gettop(L) > 1)
    {
        ptr = sfg::Scrollbar::Create(getPtr<sfg::Adjustment>(L, 1),
        static_cast<sfg::Scrollbar::Orientation> (luaL_checkoption(L, 2, "HORIZONTAL", ScrollbarOrientation)));
    }
    else
    {
        ptr = sfg::Scrollbar::Create(static_cast<sfg::Scrollbar::Orientation> (
        luaL_checkoption(L, 2, "HORIZONTAL", ScrollbarOrientation)));
    }
    putPtr<sfg::Scrollbar>(L, ptr);
    return 1;
}

int Scrollbar_GetSliderRect(lua_State * L)
{
    const sf::FloatRect r = getPtr<sfg::Scrollbar>(L, 1)->GetSliderRect();

    lua_pushnumber(L, r.left);
    lua_pushnumber(L, r.top);
    lua_pushnumber(L, r.width);
    lua_pushnumber(L, r.height);

    return 4;
}

int Scrollbar_IsDecreaseStepperPressed(lua_State * L)
{
    lua_pushboolean(L, getPtr<sfg::Scrollbar>(L, 1)->IsDecreaseStepperPressed());
    return 1;
}

int Scrollbar_IsIncreaseStepperPressed(lua_State * L)
{
    lua_pushboolean(L, getPtr<sfg::Scrollbar>(L, 1)->IsIncreaseStepperPressed());
    return 1;
}

const luaL_Reg ScrollbarReg[] = {
    { "Range", &Scrollbar_Range},
    { "Widget", &Scrollbar_Widget},
    { "Object", &Scrollbar_Object},
    { "__gc", &Scrollbar_gc},
    { "Create", &Scrollbar_Create},
    { "GetSliderRect", &Scrollbar_GetSliderRect},
    { "IsDecreaseStepperPressed", &Scrollbar_IsDecreaseStepperPressed},
    { "IsIncreaseStepperPressed", &Scrollbar_IsIncreaseStepperPressed},
    {nullptr, nullptr}
};

int openSFGScrollbar(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Scrollbar>::get());
    luaL_setfuncs(L, ScrollbarReg, 0);
    indexize(L, -1);
    lua_setglobal(L, Name<sfg::Scrollbar>::get());
    return 1;
}

}

namespace ee {

int ScrolledWindow_Container(lua_State * L)
{
    putPtr<sfg::Container>(L, getPtr<sfg::ScrolledWindow>(L, 1));
    return 1;
}

int ScrolledWindow_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::ScrolledWindow>(L, 1));
    return 1;
}

int ScrolledWindow_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::ScrolledWindow>(L, 1));
    return 1;
}

int ScrolledWindow_gc(lua_State * L)
{
    killPtr<sfg::ScrolledWindow>(L, 1);
    return 1;
}

const char * const ScrolledWindowPlacement[] = {
    "TOP_LEFT", "TOP_RIGHT", "BOTTOM_LEFT", "BOTTOM_RIGHT", "DEFAULT", nullptr
};

inline sfg::ScrolledWindow::Placement toPlacement(int i)
{
    switch (i)
    {
        case 0:case 1:case 2:case 3:
            return static_cast<sfg::ScrolledWindow::Placement> (i);
    }
    return sfg::ScrolledWindow::Placement::DEFAULT;
}

int ScrolledWindow_Create(lua_State * L)
{
    sfg::ScrolledWindow::Ptr ptr;
    if (lua_gettop(L) >= 2)
    {
        ptr = sfg::ScrolledWindow::Create(getPtr<sfg::Adjustment>(L, 1), getPtr<sfg::Adjustment>(L, 2));
    }
    else//not enough args for adjustments
    {
        ptr = sfg::ScrolledWindow::Create();
    }
    putPtr<sfg::ScrolledWindow>(L, ptr);
    return 1;
}

int ScrolledWindow_GetHorizontalAdjustment(lua_State * L)
{
    putPtr<sfg::Adjustment>(L, getPtr<sfg::ScrolledWindow>(L, 1)->GetHorizontalAdjustment());
    return 1;
}

int ScrolledWindow_SetHorizontalAdjustment(lua_State * L)
{
    getPtr<sfg::ScrolledWindow>(L, 1)->SetHorizontalAdjustment(getPtr<sfg::Adjustment>(L, 2));
    return 0;
}

int ScrolledWindow_GetVerticalAdjustment(lua_State * L)
{
    putPtr<sfg::Adjustment>(L, getPtr<sfg::ScrolledWindow>(L, 1)->GetVerticalAdjustment());
    return 1;
}

int ScrolledWindow_SetVerticalAdjustment(lua_State * L)
{
    getPtr<sfg::ScrolledWindow>(L, 1)->SetVerticalAdjustment(getPtr<sfg::Adjustment>(L, 2));
    return 0;
}

int ScrolledWindow_GetScrollbarPolicy(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::ScrolledWindow>(L, 1)->GetScrollbarPolicy());
    return 1;
}

int ScrolledWindow_SetScrollbarPolicy(lua_State * L)
{
    getPtr<sfg::ScrolledWindow>(L, 1)->SetScrollbarPolicy(luaL_checknumber(L, 2));
    return 0;
}

int ScrolledWindow_SetPlacement(lua_State * L)
{
    getPtr<sfg::ScrolledWindow>(L, 1)->SetPlacement(toPlacement(
    luaL_checkoption(L, 2, nullptr, ScrolledWindowPlacement)));
    return 0;
}

int ScrolledWindow_GetContentAllocation(lua_State * L)
{
    const sf::FloatRect r = getPtr<sfg::ScrolledWindow>(L, 1)->GetContentAllocation();

    lua_pushnumber(L, r.left);
    lua_pushnumber(L, r.top);
    lua_pushnumber(L, r.width);
    lua_pushnumber(L, r.height);

    return 4;
}

int ScrolledWindow_GetViewport(lua_State * L)
{
    //getPtr<sfg::ScrolledWindow>(L,1);
    luaL_error(L, "not implemented");
    return 0;
}

int ScrolledWindow_AddWithViewport(lua_State * L)
{
    getPtr<sfg::ScrolledWindow>(L, 1)->AddWithViewport(getPtr<sfg::Widget>(L, 2));
    return 0;
}

/* .........................
int ScrolledWindow_Add(lua_State * L)
{
    getPtr<sfg::ScrolledWindow>(L, 1)->Add(getPtr<sfg::Widget>(L, 2));
    return 0;
}
*/

int ScrolledWindow_Remove(lua_State * L)
{
    getPtr<sfg::ScrolledWindow>(L, 1)->Remove(getPtr<sfg::Widget>(L, 2));
    return 0;
}

const luaL_Reg ScrolledWindowReg[] = {
    { "Container", &ScrolledWindow_Container},
    { "Widget", &ScrolledWindow_Widget},
    { "Object", &ScrolledWindow_Object},
    { "__gc", &ScrolledWindow_gc},
    { "Create", &ScrolledWindow_Create},
    { "GetHorizontalAdjustment", &ScrolledWindow_GetHorizontalAdjustment},
    { "SetHorizontalAdjustment", &ScrolledWindow_SetHorizontalAdjustment},
    { "GetVerticalAdjustment", &ScrolledWindow_GetVerticalAdjustment},
    { "SetVerticalAdjustment", &ScrolledWindow_SetVerticalAdjustment},
    { "GetScrollbarPolicy", &ScrolledWindow_GetScrollbarPolicy},
    { "SetScrollbarPolicy", &ScrolledWindow_SetScrollbarPolicy},
    { "SetPlacement", &ScrolledWindow_SetPlacement},
    { "GetContentAllocation", &ScrolledWindow_GetContentAllocation},
    { "GetViewport", &ScrolledWindow_GetViewport},
    { "AddWithViewport", &ScrolledWindow_AddWithViewport},
    //{ "Add", &ScrolledWindow_Add},
    { "Remove", &ScrolledWindow_Remove},
    {nullptr, nullptr}
};

int openSFGScrolledWindow(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::ScrolledWindow>::get());
    luaL_setfuncs(L, ScrolledWindowReg, 0);

    lua_pushnumber(L, sfg::ScrolledWindow::HORIZONTAL_ALWAYS);
    lua_setfield(L, -2, "HORIZONTAL_ALWAYS");
    lua_pushnumber(L, sfg::ScrolledWindow::HORIZONTAL_AUTOMATIC);
    lua_setfield(L, -2, "HORIZONTAL_AUTOMATIC");
    lua_pushnumber(L, sfg::ScrolledWindow::HORIZONTAL_NEVER);
    lua_setfield(L, -2, "HORIZONTAL_NEVER");
    lua_pushnumber(L, sfg::ScrolledWindow::VERTICAL_ALWAYS);
    lua_setfield(L, -2, "VERTICAL_ALWAYS");
    lua_pushnumber(L, sfg::ScrolledWindow::VERTICAL_AUTOMATIC);
    lua_setfield(L, -2, "VERTICAL_AUTOMATIC");
    lua_pushnumber(L, sfg::ScrolledWindow::VERTICAL_NEVER);
    lua_setfield(L, -2, "VERTICAL_NEVER");
    lua_pushnumber(L, sfg::ScrolledWindow::DEFAULT);
    lua_setfield(L, -2, "DEFAULT");

    indexize(L, -1);
    lua_setglobal(L, Name<sfg::ScrolledWindow>::get());
    return 1;
}
}

namespace ee {

int Separator_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Separator>(L, 1));
    return 1;
}

int Separator_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::Separator>(L, 1));
    return 1;
}

int Separator_gc(lua_State * L)
{
    killPtr<sfg::Separator>(L, 1);
    return 0;
}

const char * const SeparatorOrientation[] = {
    "HORIZONTAL", "VERTICAL", nullptr
};

int Separator_Create(lua_State * L)
{
    putPtr<sfg::Separator>(L, sfg::Separator::Create(static_cast<sfg::Separator::Orientation> (
    luaL_checkoption(L, 2, "HORIZONTAL", SeparatorOrientation))));
    return 1;
}

int Separator_GetOrientation(lua_State * L)
{
    lua_pushstring(L, SeparatorOrientation[static_cast<int> (
    getPtr<sfg::Separator>(L, 1)->GetOrientation())]);
    return 1;
}

const luaL_Reg SeparatorReg[] = {
    { "Widget", &Separator_Widget},
    { "Object", &Separator_Object},
    { "__gc", &Separator_gc},
    { "Create", &Separator_Create},
    { "GetOrientation", &Separator_GetOrientation},
    {nullptr, nullptr}
};

int openSFGSeparator(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Separator>::get());
    luaL_setfuncs(L, SeparatorReg, 0);
    indexize(L, -1);
    lua_setglobal(L, Name<sfg::Separator>::get());
}

}

namespace ee {

int SpinButton_Entry(lua_State * L)
{
    putPtr<sfg::Entry>(L, getPtr<sfg::SpinButton>(L, 1));
    return 1;
}

int SpinButton_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::SpinButton>(L, 1));
    return 1;
}

int SpinButton_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::SpinButton>(L, 1));
    return 1;
}

int SpinButton_gc(lua_State * L)
{
    killPtr<sfg::SpinButton>(L, 1);
    return 0;
}

int SpinButton_Create(lua_State * L)
{
    sfg::SpinButton::Ptr ptr;
    if (lua_gettop(L) > 1)
    {
        ptr = sfg::SpinButton::Create(luaL_checknumber(L, 1),
        luaL_checknumber(L, 2), luaL_checknumber(L, 3));
    }
    else//<=1
    {
        ptr = sfg::SpinButton::Create(getPtr<sfg::Adjustment>(L, 1));
    }
    putPtr<sfg::SpinButton>(L, ptr);
    return 1;
}

int SpinButton_IsDecreaseStepperPressed(lua_State * L)
{
    lua_pushboolean(L, getPtr<sfg::SpinButton>(L, 1)->IsDecreaseStepperPressed());
    return 1;
}

int SpinButton_IsIncreaseStepperPressed(lua_State * L)
{
    lua_pushboolean(L, getPtr<sfg::SpinButton>(L, 1)->IsIncreaseStepperPressed());
    return 1;
}

int SpinButton_GetAdjustment(lua_State * L)
{
    putPtr<sfg::Adjustment>(L, getPtr<sfg::SpinButton>(L, 1)->GetAdjustment());
    return 1;
}

int SpinButton_SetAdjustment(lua_State * L)
{
    getPtr<sfg::SpinButton>(L, 1)->SetAdjustment(getPtr<sfg::Adjustment>(L, 2));
    return 0;
}

int SpinButton_GetValue(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::SpinButton>(L, 1)->GetValue());
    return 1;
}

int SpinButton_SetValue(lua_State * L)
{
    getPtr<sfg::SpinButton>(L, 1)->SetValue(luaL_checknumber(L, 2));
    return 0;
}

int SpinButton_GetStep(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::SpinButton>(L, 1)->GetStep());
    return 1;
}

int SpinButton_SetStep(lua_State * L)
{
    getPtr<sfg::SpinButton>(L, 1)->SetStep(luaL_checknumber(L, 2));
    return 0;
}

int SpinButton_SetRange(lua_State * L)
{
    getPtr<sfg::SpinButton>(L, 1)->SetRange(luaL_checknumber(L, 2), luaL_checknumber(L, 3));
    return 0;
}

int SpinButton_GetDigits(lua_State * L)
{
    lua_pushunsigned(L, getPtr<sfg::SpinButton>(L, 1)->GetDigits());
    return 1;
}

int SpinButton_SetDigits(lua_State * L)
{
    getPtr<sfg::SpinButton>(L, 1)->SetDigits(luaL_checkunsigned(L, 2));
    return 0;
}

int SpinButton_Configure(lua_State * L)
{
    getPtr<sfg::SpinButton>(L, 1)->Configure(getPtr<sfg::Adjustment>(L, 2),
    luaL_checknumber(L, 3), luaL_checkunsigned(L, 4));
    return 0;
}

const luaL_Reg SpinButtonReg[] = {
    { "Entry", &SpinButton_Entry},
    { "Widget", &SpinButton_Widget},
    { "Object", &SpinButton_Object},
    { "__gc", &SpinButton_gc},
    { "Create", &SpinButton_Create},
    { "IsDecreaseStepperPressed", &SpinButton_IsDecreaseStepperPressed},
    { "IsIncreaseStepperPressed", &SpinButton_IsIncreaseStepperPressed},
    { "GetAdjustment", &SpinButton_GetAdjustment},
    { "SetAdjustment", &SpinButton_SetAdjustment},
    { "GetValue", &SpinButton_GetValue},
    { "SetValue", &SpinButton_SetValue},
    { "GetStep", &SpinButton_GetStep},
    { "SetStep", &SpinButton_SetStep},
    { "SetRange", &SpinButton_SetRange},
    { "GetDigits", &SpinButton_GetDigits},
    { "SetDigits", &SpinButton_SetDigits},
    { "Configure", &SpinButton_Configure},
    {nullptr, nullptr}
};

int openSFGSpinButton(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::SpinButton>::get());
    luaL_setfuncs(L, SpinButtonReg, 0);

    putSignalId(L, sfg::SpinButton::OnValueChanged);
    lua_setfield(L, -2, "OnValueChanged");

    indexize(L, -1);
    lua_setglobal(L, Name<sfg::SpinButton>::get());
}

}

namespace ee {

int Spinner_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Spinner>(L, 1));
    return 1;
}

int Spinner_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::Spinner>(L, 1));
    return 1;
}

int Spinner_gc(lua_State * L)
{
    killPtr<sfg::Spinner>(L, 1);
    return 0;
}

int Spinner_Create(lua_State * L)
{
    putPtr<sfg::Spinner>(L, sfg::Spinner::Create());
    return 1;
}

int Spinner_Start(lua_State * L)
{
    getPtr<sfg::Spinner>(L, 1)->Start();
    return 0;
}

int Spinner_Stop(lua_State * L)
{
    getPtr<sfg::Spinner>(L, 1)->Stop();
    return 0;
}

int Spinner_Started(lua_State * L)
{
    lua_pushboolean(L, getPtr<sfg::Spinner>(L, 1)->Started());
    return 1;
}

int Spinner_GetStage(lua_State * L)
{
    lua_pushunsigned(L, getPtr<sfg::Spinner>(L, 1)->GetStage());
    return 1;
}

const luaL_Reg SpinnerReg[] = {
    { "Widget", &Spinner_Widget},
    { "Object", &Spinner_Object},
    { "__gc", &Spinner_gc},
    { "Create", &Spinner_Create},
    { "Start", &Spinner_Start},
    { "Stop", &Spinner_Stop},
    { "Started", &Spinner_Started},
    { "GetStage", &Spinner_GetStage},
    {nullptr, nullptr}
};

int openSFGSpinner(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Spinner>::get());
    luaL_setfuncs(L, SpinnerReg, 0);
    indexize(L, -1);
    lua_setglobal(L, Name<sfg::Spinner>::get());
}

}

namespace ee {

int Table_Container(lua_State * L)
{
    putPtr<sfg::Container>(L, getPtr<sfg::Table>(L, 1));
    return 1;
}

int Table_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Table>(L, 1));
    return 1;
}

int Table_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::Table>(L, 1));
    return 1;
}

int Table_gc(lua_State * L)
{
    killPtr<sfg::Table>(L, 1);
    return 0;
}

int Table_Create(lua_State * L)
{
    putPtr<sfg::Table>(L, sfg::Table::Create());
    return 1;
}

int Table_Attach(lua_State * L)
{
    //10 args function, waaat @_@
    sfg::Table::Ptr t = getPtr<sfg::Table>(L, 1);
    sfg::Widget::Ptr w = getPtr<sfg::Widget>(L, 2);

    sf::Rect<sf::Uint32> r;
    r.left = luaL_checkunsigned(L, 3);
    r.top = luaL_checkunsigned(L, 4);
    r.width = luaL_checkunsigned(L, 5);
    r.height = luaL_checkunsigned(L, 6);

    int optx = luaL_optint(L, 7, sfg::Table::EXPAND | sfg::Table::FILL);
    int opty = luaL_optint(L, 8, sfg::Table::EXPAND | sfg::Table::FILL);

    sf::Vector2f p;
    p.x = luaL_optnumber(L, 9, 0.0);
    p.y = luaL_optnumber(L, 10, 0.0);

    t->Attach(w, r, optx, opty, p);

    return 0;
}

int Table_SetColumnSpacing(lua_State * L)
{
    getPtr<sfg::Table>(L, 1)->SetColumnSpacing(luaL_checkunsigned(L, 2), luaL_checknumber(L, 3));
    return 0;
}

int Table_SetColumnSpacings(lua_State * L)
{
    getPtr<sfg::Table>(L, 1)->SetColumnSpacings(luaL_checknumber(L, 2));
    return 0;
}

int Table_SetRowSpacing(lua_State * L)
{
    getPtr<sfg::Table>(L, 1)->SetRowSpacing(luaL_checkunsigned(L, 2), luaL_checknumber(L, 3));
    return 0;
}

int Table_SetRowSpacings(lua_State * L)
{
    getPtr<sfg::Table>(L, 1)->SetRowSpacings(luaL_checknumber(L, 2));
    return 0;
}

const luaL_Reg TableReg[] = {
    { "Container", &Table_Container},
    { "Widget", &Table_Widget},
    { "Object", &Table_Object},
    { "gc", &Table_gc},
    { "Create", &Table_Create},
    { "Attach", &Table_Attach},
    { "SetColumnSpacing", &Table_SetColumnSpacing},
    { "SetColumnSpacings", &Table_SetColumnSpacings},
    { "SetRowSpacing", &Table_SetRowSpacing},
    { "SetRowSpacings", &Table_SetRowSpacings},
    {nullptr, nullptr}
};

int openSFGTable(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Table>::get());
    luaL_setfuncs(L, TableReg, 0);

    lua_pushnumber(L, sfg::Table::FILL);
    lua_setfield(L, -2, "FILL");
    lua_pushnumber(L, sfg::Table::EXPAND);
    lua_setfield(L, -2, "EXPAND");

    indexize(L, -1);
    lua_setglobal(L, Name<sfg::Table>::get());
}

}

namespace ee {

int ToggleButton_Button(lua_State * L)
{
    putPtr<sfg::Button>(L, getPtr<sfg::ToggleButton>(L, 1));
    return 1;
}

int ToggleButton_Bin(lua_State * L)
{
    putPtr<sfg::Bin>(L, getPtr<sfg::ToggleButton>(L, 1));
    return 1;
}

int ToggleButton_Container(lua_State * L)
{
    putPtr<sfg::Container>(L, getPtr<sfg::ToggleButton>(L, 1));
    return 1;
}

int ToggleButton_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::ToggleButton>(L, 1));
    return 1;
}

int ToggleButton_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::ToggleButton>(L, 1));
    return 1;
}

int ToggleButton_gc(lua_State * L)
{
    killPtr<sfg::ToggleButton>(L, 1);
    return 0;
}

int ToggleButton_Create(lua_State * L)
{
    putPtr<sfg::ToggleButton>(L, sfg::ToggleButton::Create(luaL_optstring(L, 1, "")));
    return 1;
}

int ToggleButton_SetActive(lua_State * L)
{
    getPtr<sfg::ToggleButton>(L, 1)->SetActive(checkbool(L, 2));
    return 0;
}

int ToggleButton_IsActive(lua_State * L)
{
    lua_pushboolean(L, getPtr<sfg::ToggleButton>(L, 1)->IsActive());
    return 1;
}

const luaL_Reg ToggleButtonReg[] = {
    { "Button", &ToggleButton_Button},
    { "Bin", &ToggleButton_Bin},
    { "Container", &ToggleButton_Container},
    { "Widget", &ToggleButton_Widget},
    { "Object", &ToggleButton_Object},
    { "__gc", &ToggleButton_gc},
    { "Create", &ToggleButton_Create},
    { "SetActive", &ToggleButton_SetActive},
    { "IsActive", &ToggleButton_IsActive},
    {nullptr, nullptr}
};

int openSFGToggleButton(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::ToggleButton>::get());
    luaL_setfuncs(L, ToggleButtonReg, 0);
    indexize(L, -1);

    putSignalId(L, sfg::ToggleButton::OnToggle);
    lua_setfield(L, -2, "OnToggle");

    lua_setglobal(L, Name<sfg::ToggleButton>::get());
    return 1;
}

}

namespace ee {

int Widget_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::Widget>(L, 1));
    return 1;
}

int Widget_gc(lua_State * L)
{
    killPtr<sfg::Widget>(L, 1);
    return 0;
}

const char * const WidgetState[] = {
    "NORMAL", "ACTIVE", "PRELIGHT", "SELECTED", "INSENSITIVE", nullptr
};

int Widget_IsLocallyVisible(lua_State * L)
{
    lua_pushboolean(L, getPtr<sfg::Widget>(L, 1)->IsLocallyVisible());
    return 1;
}

int Widget_IsGloballyVisible(lua_State * L)
{
    lua_pushboolean(L, getPtr<sfg::Widget>(L, 1)->IsGloballyVisible());
    return 1;
}

int Widget_Show(lua_State * L)
{
    getPtr<sfg::Widget>(L, 1)->Show(optbool(L, 2, true));
    return 0;
}

int Widget_GetName(lua_State * L)
{
    lua_pushstring(L, getPtr<sfg::Widget>(L, 1)->GetName().c_str());
    return 1;
}

int Widget_GrabFocus(lua_State * L)
{
    getPtr<sfg::Widget>(L, 1)->GrabFocus();
    return 0;
}

int Widget_HasFocus(lua_State * L)
{
    lua_pushboolean(L, getPtr<sfg::Widget>(L, 1)->HasFocus());
    return 1;
}

int Widget_SetActiveWidget(lua_State * L)
{
    getPtr<sfg::Widget>(L, 1)->SetActiveWidget();
    return 0;
}

int Widget_IsActiveWidget(lua_State * L)
{
    lua_pushboolean(L, getPtr<sfg::Widget>(L, 1)->IsActiveWidget());
    return 1;
}

int Widget_SetAllocation(lua_State * L)
{
    auto w = getPtr<sfg::Widget>(L, 1);
    sf::FloatRect r;
    r.left = luaL_checknumber(L, 2);
    r.top = luaL_checknumber(L, 3);
    r.width = luaL_checknumber(L, 4);
    r.height = luaL_checknumber(L, 5);
    w->SetAllocation(r);
    return 0;
}

int Widget_RequestResize(lua_State * L)
{
    getPtr<sfg::Widget>(L, 1)->RequestResize();
    return 0;
}

int Widget_GetAllocation(lua_State * L)
{
    sf::FloatRect r = getPtr<sfg::Widget>(L, 1)->GetAllocation();
    lua_pushnumber(L, r.left);
    lua_pushnumber(L, r.top);
    lua_pushnumber(L, r.width);
    lua_pushnumber(L, r.height);
    return 4;
}

int Widget_GetRequisition(lua_State * L)
{
    sf::Vector2f v = getPtr<sfg::Widget>(L, 1)->GetRequisition();
    lua_pushnumber(L, v.x);
    lua_pushnumber(L, v.y);
    return 2;
}

int Widget_SetRequisition(lua_State * L)
{
    auto w = getPtr<sfg::Widget>(L, 1);
    sf::Vector2f v;
    v.x = luaL_optnumber(L, 2, 0.0);
    v.y = luaL_optnumber(L, 3, 0.0);
    w->SetRequisition(v);
    return 0;
}

int Widget_SetPosition(lua_State * L)
{
    auto w = getPtr<sfg::Widget>(L, 1);
    sf::Vector2f v;
    v.x = luaL_checknumber(L, 2);
    v.y = luaL_checknumber(L, 3);
    w->SetPosition(v);
    return 0;
}

int Widget_Update(lua_State * L)
{
    getPtr<sfg::Widget>(L, 1)->Update(luaL_checknumber(L, 2));
    return 0;
}

int Widget_Invalidate(lua_State * L)
{
    getPtr<sfg::Widget>(L, 1)->Invalidate();
    return 0;
}

int Widget_SetParent(lua_State * L)
{
    getPtr<sfg::Widget>(L, 1)->SetParent(getPtr<sfg::Widget>(L, 2));
    return 0;
}

int Widget_GetParent(lua_State * L)
{
    putPtr<sfg::Container>(L, getPtr<sfg::Widget>(L, 1)->GetParent());
    return 1;
}

int Widget_SetState(lua_State * L)
{
    getPtr<sfg::Widget>(L, 1)->SetState(static_cast<sfg::Widget::State> (
    luaL_checkoption(L, 2, nullptr, WidgetState)));
    return 0;
}

int Widget_GetState(lua_State * L)
{
    switch (getPtr<sfg::Widget>(L, 1)->GetState())
    {
        case sfg::Widget::State::NORMAL:
            lua_pushliteral(L, "NORMAL");
            break;

        case sfg::Widget::State::ACTIVE:
            lua_pushliteral(L, "ACTIVE");
            break;

        case sfg::Widget::State::PRELIGHT:
            lua_pushliteral(L, "PRELIGHT");
            break;

        case sfg::Widget::State::SELECTED:
            lua_pushliteral(L, "SELECTED");
            break;

        case sfg::Widget::State::INSENSITIVE:
            lua_pushliteral(L, "INSENSITIVE");
            break;
    }
    return 1;
}

int Widget_GetAbsolutePosition(lua_State * L)
{
    sf::Vector2f v = getPtr<sfg::Widget>(L, 1)->GetAbsolutePosition();
    lua_pushnumber(L, v.x);
    lua_pushnumber(L, v.y);
    return 2;
}

int Widget_HandleAbsolutePositionChange(lua_State * L)
{
    getPtr<sfg::Widget>(L, 1)->HandleAbsolutePositionChange();
    return 0;
}

int Widget_HandleGlobalVisibilityChange(lua_State * L)
{
    getPtr<sfg::Widget>(L, 1)->HandleGlobalVisibilityChange();
    return 0;
}

int Widget_UpdateDrawablePosition(lua_State * L)
{
    getPtr<sfg::Widget>(L, 1)->UpdateDrawablePosition();
    return 0;
}

int Widget_SetId(lua_State * L)
{
    getPtr<sfg::Widget>(L, 1)->SetId(luaL_checkstring(L, 2));
    return 0;
}

int Widget_GetId(lua_State * L)
{
    lua_pushstring(L, getPtr<sfg::Widget>(L, 1)->GetId().c_str());
    return 1;
}

int Widget_SetClass(lua_State * L)
{
    getPtr<sfg::Widget>(L, 1)->SetClass(luaL_checkstring(L, 2));
    return 0;
}

int Widget_GetClass(lua_State * L)
{
    lua_pushstring(L, getPtr<sfg::Widget>(L, 1)->GetClass().c_str());
    return 1;
}

int Widget_GetWidgetById(lua_State * L)
{
    putPtr<sfg::Widget>(L, sfg::Widget::GetWidgetById(luaL_checkstring(L, 1)));
    return 1;
}

int Widget_GetWidgetsByClass(lua_State * L)
{
    auto wv = sfg::Widget::GetWidgetsByClass(luaL_checkstring(L, 1));
    lua_newtable(L);
    for (int i = 0; i < wv.size(); ++i)
    {
        putPtr<sfg::Widget>(L, wv[i]);
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

int Widget_Refresh(lua_State * L)
{
    getPtr<sfg::Widget>(L, 1)->Refresh();
    return 0;
}

int Widget_RefreshAll(lua_State * L)
{
    sfg::Widget::RefreshAll();
    return 0;
}

int Widget_SetHierarchyLevel(lua_State * L)
{
    getPtr<sfg::Widget>(L, 1)->SetHierarchyLevel(luaL_checkint(L, 2));
    return 0;
}

int Widget_GetHierarchyLevel(lua_State * L)
{
    lua_pushinteger(L, getPtr<sfg::Widget>(L, 1)->GetHierarchyLevel());
    return 1;
}

//void SetViewport(RendererViewport::Ptr viewport); // no?

//RendererViewport::Ptr GetViewport() const; // no?

int Widget_GetZOrder(lua_State * L)
{
    lua_pushinteger(L, getPtr<sfg::Widget>(L, 1)->GetZOrder());
    return 1;
}

int Widget_SetZOrder(lua_State * L)
{
    getPtr<sfg::Widget>(L, 1)->SetZOrder(luaL_checkint(L, 2));
    return 0;
}

int Widget_HasModal(lua_State * L)
{
    lua_pushboolean(L, sfg::Widget::HasModal());
    return 1;
}

const luaL_Reg WidgetReg[] = {
    { "Object", &Widget_Object},
    { "__gc", &Widget_gc},
    { "IsLocallyVisible", &Widget_IsLocallyVisible},
    { "IsGloballyVisible", &Widget_IsGloballyVisible},
    { "Show", &Widget_Show},
    { "GetName", &Widget_GetName},
    { "GrabFocus", &Widget_GrabFocus},
    { "HasFocus", &Widget_HasFocus},
    { "SetActiveWidget", &Widget_SetActiveWidget},
    { "IsActiveWidget", &Widget_IsActiveWidget},
    { "SetAllocation", &Widget_SetAllocation},
    { "RequestResize", &Widget_RequestResize},
    { "GetAllocation", &Widget_GetAllocation},
    { "GetRequisition", &Widget_GetRequisition},
    { "SetRequisition", &Widget_SetRequisition},
    { "SetPosition", &Widget_SetPosition},
    { "Update", &Widget_Update},
    { "Invalidate", &Widget_Invalidate},
    { "SetParent", &Widget_SetParent},
    { "GetParent", &Widget_GetParent},
    { "SetState", &Widget_SetState},
    { "GetState", &Widget_GetState},
    { "GetAbsolutePosition", &Widget_GetAbsolutePosition},
    { "HandleAbsolutePositionChange", &Widget_HandleAbsolutePositionChange},
    { "HandleGlobalVisibilityChange", &Widget_HandleGlobalVisibilityChange},
    { "UpdateDrawablePosition", &Widget_UpdateDrawablePosition},
    { "SetId", &Widget_SetId},
    { "GetId", &Widget_GetId},
    { "SetClass", &Widget_SetClass},
    { "GetClass", &Widget_GetClass},
    { "GetWidgetById", &Widget_GetWidgetById},
    { "GetWidgetsByClass", &Widget_GetWidgetsByClass},
    { "Refresh", &Widget_Refresh},
    { "RefreshAll", &Widget_RefreshAll},
    { "SetHierarchyLevel", &Widget_SetHierarchyLevel},
    { "GetHierarchyLevel", &Widget_GetHierarchyLevel},
    { "GetZOrder", &Widget_GetZOrder},
    { "SetZOrder", &Widget_SetZOrder},
    { "HasModal", &Widget_HasModal},
    {nullptr, nullptr}
};

int openSFGWidget(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Widget>::get());
    luaL_setfuncs(L, WidgetReg, 0);
    indexize(L, -1);

    putSignalId(L, sfg::Widget::OnStateChange);
    lua_setfield(L, -2, "OnStateChange");
    putSignalId(L, sfg::Widget::OnGainFocus);
    lua_setfield(L, -2, "OnGainFocus");
    putSignalId(L, sfg::Widget::OnLostFocus);
    lua_setfield(L, -2, "OnLostFocus");
    putSignalId(L, sfg::Widget::OnExpose);
    lua_setfield(L, -2, "OnExpose");
    putSignalId(L, sfg::Widget::OnSizeAllocate);
    lua_setfield(L, -2, "OnSizeAllocate");
    putSignalId(L, sfg::Widget::OnSizeRequest);
    lua_setfield(L, -2, "OnSizeRequest");

    putSignalId(L, sfg::Widget::OnMouseEnter);
    lua_setfield(L, -2, "OnMouseEnter");
    putSignalId(L, sfg::Widget::OnMouseLeave);
    lua_setfield(L, -2, "OnMouseLeave");
    putSignalId(L, sfg::Widget::OnMouseMove);
    lua_setfield(L, -2, "OnMouseMove");
    putSignalId(L, sfg::Widget::OnMouseLeftPress);
    lua_setfield(L, -2, "OnMouseLeftPress");
    putSignalId(L, sfg::Widget::OnMouseRightPress);
    lua_setfield(L, -2, "OnMouseRightPress");
    putSignalId(L, sfg::Widget::OnMouseLeftRelease);
    lua_setfield(L, -2, "OnMouseLeftRelease");
    putSignalId(L, sfg::Widget::OnMouseRightRelease);
    lua_setfield(L, -2, "OnMouseRightRelease");
    putSignalId(L, sfg::Widget::OnLeftClick);
    lua_setfield(L, -2, "OnLeftClick");
    putSignalId(L, sfg::Widget::OnRightClick);
    lua_setfield(L, -2, "OnRightClick");

    putSignalId(L, sfg::Widget::OnKeyPress);
    lua_setfield(L, -2, "OnKeyPress");
    putSignalId(L, sfg::Widget::OnKeyRelease);
    lua_setfield(L, -2, "OnKeyRelease");
    putSignalId(L, sfg::Widget::OnText);
    lua_setfield(L, -2, "OnText");


    lua_setglobal(L, Name<sfg::Widget>::get());
    return 1;
}

}

namespace ee {

int Window_Bin(lua_State * L)
{
    putPtr<sfg::Bin>(L, getPtr<sfg::Window>(L, 1));
    return 1;
}

int Window_Container(lua_State * L)
{
    putPtr<sfg::Container>(L, getPtr<sfg::Window>(L, 1));
    return 1;
}

int Window_Widget(lua_State * L)
{
    putPtr<sfg::Widget>(L, getPtr<sfg::Window>(L, 1));
    return 1;
}

int Window_Object(lua_State * L)
{
    putPtr<sfg::Object>(L, getPtr<sfg::Window>(L, 1));
    return 1;
}

int Window_gc(lua_State * L)
{
    killPtr<sfg::Window>(L, 1);
    return 0;
}

int Window_Create(lua_State * L)
{
    putPtr<sfg::Window>(L, sfg::Window::Create(luaL_optnumber(L, 1, sfg::Window::TOPLEVEL)));
    return 1;
}

int Window_SetTitle(lua_State * L)
{
    getPtr<sfg::Window>(L, 1)->SetTitle(luaL_checkstring(L, 2));
    return 0;
}

int Window_GetTitle(lua_State * L)
{
    lua_pushstring(L, getPtr<sfg::Window>(L, 1)->GetTitle().toAnsiString().c_str());
    return 1;
}

int Window_GetClientRect(lua_State * L)
{
    const sf::FloatRect f = getPtr<sfg::Window>(L, 1)->GetClientRect();

    lua_pushnumber(L, f.left);
    lua_pushnumber(L, f.top);
    lua_pushnumber(L, f.width);
    lua_pushnumber(L, f.height);

    return 4;
}

int Window_SetStyle(lua_State * L)
{
    getPtr<sfg::Window>(L, 1)->SetStyle(luaL_checknumber(L, 2));
    return 0;
}

int Window_GetStyle(lua_State * L)
{
    lua_pushnumber(L, getPtr<sfg::Window>(L, 1)->GetStyle());
    return 1;
}

int Window_HasStyle(lua_State * L)
{
    lua_pushboolean(L, getPtr<sfg::Window>(L, 1)->HasStyle(
    static_cast<sfg::Window::Style> (luaL_checknumber(L, 2))));
    return 1;
}

const luaL_Reg WindowReg[] = {
    { "Bin", &Window_Bin},
    { "Container", &Window_Container},
    { "Widget", &Window_Widget},
    { "Object", &Window_Object},
    { "__gc", &Window_gc},
    { "Create", &Window_Create},
    { "SetTitle", &Window_SetTitle},
    { "GetTitle", &Window_GetTitle},
    { "GetClientRect", &Window_GetClientRect},
    { "SetStyle", &Window_SetStyle},
    { "GetStyle", &Window_GetStyle},
    { "HasStyle", &Window_HasStyle},
    {nullptr, nullptr}
};

int openSFGWindow(lua_State * L)
{
    luaL_newmetatable(L, Name<sfg::Window>::get());
    luaL_setfuncs(L, WindowReg, 0);

    lua_pushnumber(L, sfg::Window::NO_STYLE);
    lua_setfield(L, -2, "NO_STYLE");
    lua_pushnumber(L, sfg::Window::TITLEBAR);
    lua_setfield(L, -2, "TITLEBAR");
    lua_pushnumber(L, sfg::Window::BACKGROUND);
    lua_setfield(L, -2, "BACKGROUND");

    lua_pushnumber(L, sfg::Window::RESIZE);
    lua_setfield(L, -2, "RESIZE");
    lua_pushnumber(L, sfg::Window::SHADOW);
    lua_setfield(L, -2, "SHADOW");
    lua_pushnumber(L, sfg::Window::TOPLEVEL);
    lua_setfield(L, -2, "TOPLEVEL");

    indexize(L, -1);
    lua_setglobal(L, Name<sfg::Window>::get());

    return 1;
}

}

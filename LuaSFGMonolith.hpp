/* 
 * File:   Adjustment.hpp
 * Author: frex
 *
 * Created on November 23, 2013, 4:55 PM
 */

#ifndef ADJUSTMENT_HPP
#define	ADJUSTMENT_HPP

struct lua_State;

namespace ee {

int openSFGAdjustment(lua_State * L);

}

#endif	/* ADJUSTMENT_HPP */

/* 
 * File:   Alignment.hpp
 * Author: frex
 *
 * Created on November 23, 2013, 5:01 PM
 */

#ifndef ALIGNMENT_HPP
#define	ALIGNMENT_HPP

struct lua_State;
namespace ee {

int openSFGAlignment(lua_State * L);

}

#endif	/* ALIGNMENT_HPP */

/* 
 * File:   Bin.hpp
 * Author: frex
 *
 * Created on November 23, 2013, 5:33 PM
 */

#ifndef BIN_HPP
#define	BIN_HPP

struct lua_State;

namespace ee {

int openSFGBin(lua_State * L);

}

#endif	/* BIN_HPP */

/* 
 * File:   Box.hpp
 * Author: frex
 *
 * Created on November 23, 2013, 5:44 PM
 */

#ifndef BOX_HPP
#define	BOX_HPP

struct lua_State;

namespace ee {

int openSFGBox(lua_State * L);

}

#endif	/* BOX_HPP */

/* 
 * File:   Button.hpp
 * Author: frex
 *
 * Created on November 23, 2013, 6:10 PM
 */

#ifndef BUTTON_HPP
#define	BUTTON_HPP

struct lua_State;

namespace ee {

int openSFGButton(lua_State * L);

}

#endif	/* BUTTON_HPP */

/* 
 * File:   CheckButton.hpp
 * Author: frex
 *
 * Created on November 24, 2013, 2:40 PM
 */

#ifndef CHECKBUTTON_HPP
#define	CHECKBUTTON_HPP

struct lua_State;

namespace ee {

int openSFGCheckButton(lua_State * L);

}

#endif	/* CHECKBUTTON_HPP */

/* 
 * File:   ComboBox..hpp
 * Author: frex
 *
 * Created on November 24, 2013, 3:18 PM
 */

#ifndef COMBOBOX__HPP
#define	COMBOBOX__HPP

struct lua_State;

namespace ee {

int openSFGComboBox(lua_State * L);

}

#endif	/* COMBOBOX__HPP */

/* 
 * File:   Container.hpp
 * Author: frex
 *
 * Created on November 24, 2013, 12:16 PM
 */

#ifndef CONTAINER_HPP
#define	CONTAINER_HPP

struct lua_State;

namespace ee {

int openSFGContainer(lua_State * L);

}

#endif	/* CONTAINER_HPP */

/* 
 * File:   Entry,hpp.hpp
 * Author: frex
 *
 * Created on November 24, 2013, 10:52 AM
 */

#ifndef ENTRY_HPP_HPP
#define	ENTRY_HPP_HPP

struct lua_State;

namespace ee {

int openSFGEntry(lua_State * L);

}

#endif	/* ENTRY_HPP_HPP */

/* 
 * File:   Fixed.hpp
 * Author: frex
 *
 * Created on November 24, 2013, 3:43 PM
 */

#ifndef FIXED_HPP
#define	FIXED_HPP

struct lua_State;

namespace ee {

int openSFGFixed(lua_State * L);

}

#endif	/* FIXED_HPP */

/* 
 * File:   Frame.hpp
 * Author: frex
 *
 * Created on November 24, 2013, 3:51 PM
 */

#ifndef FRAME_HPP
#define	FRAME_HPP

struct lua_State;

namespace ee {

int openSFGFrame(lua_State * L);

}

#endif	/* FRAME_HPP */

/* 
 * File:   GlobalCasts.hpp
 * Author: frex
 *
 * Created on November 25, 2013, 6:59 AM
 */

#ifndef GLOBALCASTS_HPP
#define	GLOBALCASTS_HPP

struct lua_State;

namespace ee{

int openSFGCasts(lua_State * L);

}

#endif	/* GLOBALCASTS_HPP */

/* 
 * File:   Image.hpp
 * Author: frex
 *
 * Created on November 24, 2013, 4:01 PM
 */

#ifndef IMAGE_HPP
#define	IMAGE_HPP

struct lua_State;

namespace ee {

int openSFGImage(lua_State * L);

}

#endif	/* IMAGE_HPP */

/* 
 * File:   Label.hpp
 * Author: frex
 *
 * Created on November 24, 2013, 10:38 AM
 */

#ifndef LABEL_HPP
#define	LABEL_HPP

struct lua_State;

namespace ee {

int openSFGLabel(lua_State * L);

}

#endif	/* LABEL_HPP */

/* 
 * File:   LuaSFG.hpp
 * Author: frex
 *
 * Created on November 23, 2013, 9:49 AM
 */

#ifndef LUASFG_HPP
#define	LUASFG_HPP

struct lua_State;

namespace ee {

int openLuaSFG(lua_State * L);




}

#endif	/* LUASFG_HPP */

/* 
 * File:   NameAndMake.hpp
 * Author: frex
 *
 * Created on November 23, 2013, 4:55 PM
 */

#ifndef NAMEANDMAKE_HPP
#define	NAMEANDMAKE_HPP

#include <cassert>
#include <lua.hpp>
#include <new>
#include <memory>

namespace ee {

//strict opt and check bool

inline bool optbool(lua_State * L, int n, bool d)
{
    if (lua_isnoneornil(L, n))return d; //none = missing, nil = passed nil
    luaL_checktype(L, n, LUA_TBOOLEAN);
    return lua_toboolean(L, n);
}

inline bool checkbool(lua_State * L, int n)
{
    luaL_checktype(L, n, LUA_TBOOLEAN);
    return lua_toboolean(L, n);
}

//names for lua:

template <typename T>
class Name
{

public:

    static const char * get()
    {
        assert(false);
        return nullptr;
    }
};

template<> class Name<sfg::Adjustment>
{

public:

    static const char * get()
    {
        return "Adjustment";
    }
};

template<> class Name<sfg::Alignment>
{

public:

    static const char * get()
    {
        return "Alignment";
    }
};

template<> class Name<sfg::Bin>
{

public:

    static const char * get()
    {
        return "Bin";
    }
};

template<> class Name<sfg::Box>
{

public:

    static const char * get()
    {
        return "Box";
    }
};

template<> class Name<sfg::Button>
{

public:

    static const char * get()
    {
        return "Button";
    }
};

template<> class Name<sfg::Canvas>
{

public:

    static const char * get()
    {
        return "Canvas";
    }
};

template<> class Name<sfg::CheckButton>
{

public:

    static const char * get()
    {
        return "CheckButton";
    }
};

template<> class Name<sfg::ComboBox>
{

public:

    static const char * get()
    {
        return "ComboBox";
    }
};

template<> class Name<sfg::Container>
{

public:

    static const char * get()
    {
        return "Container";
    }
};

template<> class Name<sfg::Context>
{

public:

    static const char * get()
    {
        return "Context";
    }
};

template<> class Name<sfg::Desktop>
{

public:

    static const char * get()
    {
        return "Desktop";
    }
};

template<> class Name<sfg::Engine>
{

public:

    static const char * get()
    {
        return "Engine";
    }
};

template<> class Name<sfg::Entry>
{

public:

    static const char * get()
    {
        return "Entry";
    }
};

template<> class Name<sfg::Fixed>
{

public:

    static const char * get()
    {
        return "Fixed";
    }
};

template<> class Name<sfg::Frame>
{

public:

    static const char * get()
    {
        return "Frame";
    }
};

template<> class Name<sfg::Image>
{

public:

    static const char * get()
    {
        return "Image";
    }
};

template<> class Name<sfg::Label>
{

public:

    static const char * get()
    {
        return "Label";
    }
};

template<> class Name<sfg::Misc>
{

public:

    static const char * get()
    {
        return "Misc";
    }
};

template<> class Name<sfg::Notebook>
{

public:

    static const char * get()
    {
        return "Notebook";
    }
};

template<> class Name<sfg::Object>
{

public:

    static const char * get()
    {
        return "Object";
    }
};

template<> class Name<sfg::ProgressBar>
{

public:

    static const char * get()
    {
        return "ProgressBar";
    }
};

template<> class Name<sfg::RadioButton>
{

public:

    static const char * get()
    {
        return "RadioButton";
    }
};

template<> class Name<sfg::RadioButton::RadioButtonGroup>
{

public:

    static const char * get()
    {
        return "RadioButtonGroup";
    }
};

template<> class Name<sfg::Range>
{

public:

    static const char * get()
    {
        return "Range";
    }
};

template<> class Name<sfg::RendererViewport>
{

public:

    static const char * get()
    {
        return "RendererViewport";
    }
};

template<> class Name<sfg::Scale>
{

public:

    static const char * get()
    {
        return "Scale";
    }
};

template<> class Name<sfg::Scrollbar>
{

public:

    static const char * get()
    {
        return "Scrollbar";
    }
};

template<> class Name<sfg::ScrolledWindow>
{

public:

    static const char * get()
    {
        return "ScrolledWindow";
    }
};

template<> class Name<sfg::Selector>
{

public:

    static const char * get()
    {
        return "Selector";
    }
};

template<> class Name<sfg::Separator>
{

public:

    static const char * get()
    {
        return "Separator";
    }
};

template<> class Name<sfg::SFGUI>
{

public:

    static const char * get()
    {
        return "SFGUI";
    }
};

template<> class Name<sfg::Signal>
{

public:

    static const char * get()
    {
        return "Signal";
    }
};

template<> class Name<sfg::SpinButton>
{

public:

    static const char * get()
    {
        return "SpinButton";
    }
};

template<> class Name<sfg::Spinner>
{

public:

    static const char * get()
    {
        return "Spinner";
    }
};

template<> class Name<sfg::Table>
{

public:

    static const char * get()
    {
        return "Table";
    }
};

template<> class Name<sfg::ToggleButton>
{

public:

    static const char * get()
    {
        return "ToggleButton";
    }
};

template<> class Name<sfg::Viewport>
{

public:

    static const char * get()
    {
        return "Viewport";
    }
};

template<> class Name<sfg::Widget>
{

public:

    static const char * get()
    {
        return "Widget";
    }
};

template<> class Name<sfg::Window>
{

public:

    static const char * get()
    {
        return "Window";
    }
};

template<> class Name<sfg::Signal::SignalID>
{

public:

    static const char * get()
    {
        return "SignalID";
    }
};

//functions to make and kill shared ptr from sfg:

template <typename T>
inline typename T::Ptr putPtr(lua_State * L, typename T::Ptr ptr)
{
    if (ptr)
    {
        void * ud = lua_newuserdata(L, sizeof (ptr));
        luaL_setmetatable(L, Name<T>::get());
        new (ud) typename T::Ptr(ptr); //placement new
    }
    else
    {
        lua_pushnil(L);
    }
    return ptr;
}

template <typename T>
inline typename T::Ptr getPtr(lua_State * L, int n)
{
    void * ud = luaL_checkudata(L, n, Name<T>::get());
    return *static_cast<typename T::Ptr*> (ud);
}

template <typename T>
inline void killPtr(lua_State * L, int n)
{
    void * ud = luaL_checkudata(L, n, Name<T>::get());
    static_cast<typename T::Ptr*> (ud)->~shared_ptr(); //call dtor
}

//for making metatable have __index for proper method calls

inline void indexize(lua_State * L, int n)
{
    n = lua_absindex(L, n);
    lua_pushvalue(L, n);
    lua_setfield(L, n, "__index"); //set __index to ourself
}

inline sfg::Signal::SignalID& getSignalId(lua_State * L, int n)
{
    void * ud = luaL_checkudata(L, n, Name<sfg::Signal::SignalID>::get());
    return * * static_cast<sfg::Signal::SignalID**> (ud);
}

inline void putSignalId(lua_State * L, sfg::Signal::SignalID& sid)
{
    void * ud = lua_newuserdata(L, sizeof (sfg::Signal::SignalID*));
    //ud is pointer to a pointer to signalid
    (*static_cast<sfg::Signal::SignalID**> (ud)) = &sid;
    luaL_setmetatable(L, Name<sfg::Signal::SignalID>::get());
}

}

#endif	/* NAMEANDMAKE_HPP */

/* 
 * File:   Notebook.hpp
 * Author: frex
 *
 * Created on November 24, 2013, 9:02 AM
 */

#ifndef NOTEBOOK_HPP
#define	NOTEBOOK_HPP

struct lua_State;

namespace ee {

int openSFGNotebook(lua_State * L);

}

#endif	/* NOTEBOOK_HPP */

/* 
 * File:   Object.hpp
 * Author: frex
 *
 * Created on November 24, 2013, 4:10 PM
 */

#ifndef OBJECT_HPP
#define	OBJECT_HPP

struct lua_State;

namespace ee {

int openSFGObject(lua_State * L);

}

#endif	/* OBJECT_HPP */

/* 
 * File:   ProgressBar.hpp
 * Author: frex
 *
 * Created on November 25, 2013, 6:54 AM
 */

#ifndef PROGRESSBAR_HPP
#define	PROGRESSBAR_HPP

struct lua_State;

namespace ee{

int openSFGProgressBar(lua_State * L);

}

#endif	/* PROGRESSBAR_HPP */

/* 
 * File:   RadioButtonGroup.hpp
 * Author: frex
 *
 * Created on November 25, 2013, 6:55 AM
 */

#ifndef RADIOBUTTONGROUP_HPP
#define	RADIOBUTTONGROUP_HPP

struct lua_State;

namespace ee{

int openSFGRadioButtonGroup(lua_State * L);

}

#endif	/* RADIOBUTTONGROUP_HPP */

/* 
 * File:   RadioButton.hpp
 * Author: frex
 *
 * Created on November 25, 2013, 6:55 AM
 */

#ifndef RADIOBUTTON_HPP
#define	RADIOBUTTON_HPP

struct lua_State;

namespace ee {

int openSFGRadioButton(lua_State * L);

}

#endif	/* RADIOBUTTON_HPP */

/* 
 * File:   Range.hpp
 * Author: frex
 *
 * Created on November 25, 2013, 6:56 AM
 */

#ifndef RANGE_HPP
#define	RANGE_HPP

struct lua_State;

namespace ee{

int openSFGRange(lua_State * L);

}


#endif	/* RANGE_HPP */

/* 
 * File:   Scale.hpp
 * Author: frex
 *
 * Created on November 25, 2013, 6:56 AM
 */

#ifndef SCALE_HPP
#define	SCALE_HPP

struct lua_State;

namespace ee{

int openSFGScale(lua_State * L);

}

#endif	/* SCALE_HPP */

/* 
 * File:   ScrollBar.hpp
 * Author: frex
 *
 * Created on November 25, 2013, 6:56 AM
 */

#ifndef SCROLLBAR_HPP
#define	SCROLLBAR_HPP

struct lua_State;

namespace ee{

int openSFGScrollbar(lua_State * L);

}

#endif	/* SCROLLBAR_HPP */

/* 
 * File:   ScrolledWindow.hpp
 * Author: frex
 *
 * Created on November 25, 2013, 6:57 AM
 */

#ifndef SCROLLEDWINDOW_HPP
#define	SCROLLEDWINDOW_HPP

struct lua_State;

namespace ee{

int openSFGScrolledWindow(lua_State * L);

}

#endif	/* SCROLLEDWINDOW_HPP */

/* 
 * File:   Separator.hpp
 * Author: frex
 *
 * Created on November 25, 2013, 6:57 AM
 */

#ifndef SEPARATOR_HPP
#define	SEPARATOR_HPP

struct lua_State;

namespace ee{

int openSFGSeparator(lua_State * L);

}

#endif	/* SEPARATOR_HPP */

/* 
 * File:   SpinButton.hpp
 * Author: frex
 *
 * Created on November 25, 2013, 6:58 AM
 */

#ifndef SPINBUTTON_HPP
#define	SPINBUTTON_HPP

struct lua_State;

namespace ee{

int openSFGSpinButton(lua_State * L);

}

#endif	/* SPINBUTTON_HPP */

/* 
 * File:   Spinner.hpp
 * Author: frex
 *
 * Created on November 25, 2013, 6:58 AM
 */

#ifndef SPINNER_HPP
#define	SPINNER_HPP

struct lua_State;

namespace ee{

int openSFGSpinner(lua_State * L);

}


#endif	/* SPINNER_HPP */

/* 
 * File:   Table.hpp
 * Author: frex
 *
 * Created on November 25, 2013, 6:58 AM
 */

#ifndef TABLE_HPP
#define	TABLE_HPP

struct lua_State;

namespace ee{

int openSFGTable(lua_State * L);

}


#endif	/* TABLE_HPP */

/* 
 * File:   ToggleButton.hpp
 * Author: frex
 *
 * Created on November 24, 2013, 2:49 PM
 */

#ifndef TOGGLEBUTTON_HPP
#define	TOGGLEBUTTON_HPP

struct lua_State;

namespace ee {

int openSFGToggleButton(lua_State * L);

}

#endif	/* TOGGLEBUTTON_HPP */

/* 
 * File:   Widget.hpp
 * Author: frex
 *
 * Created on November 24, 2013, 12:35 PM
 */

#ifndef WIDGET_HPP
#define	WIDGET_HPP

struct lua_State;

namespace ee {

int openSFGWidget(lua_State * L);

}

#endif	/* WIDGET_HPP */

/* 
 * File:   Window.hpp
 * Author: frex
 *
 * Created on November 23, 2013, 6:30 PM
 */

#ifndef WINDOW_HPP
#define	WINDOW_HPP

struct lua_State;

namespace ee {

int openSFGWindow(lua_State * L);

}


#endif	/* WINDOW_HPP */


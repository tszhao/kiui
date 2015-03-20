//  Copyright (c) 2015 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#ifndef MK_LIST_H_INCLUDED
#define MK_LIST_H_INCLUDED

/* mk headers */
#include <Object/mkTyped.h>
#include <Ui/mkUiForward.h>
#include <Ui/Scheme/mkScheme.h>
#include <Ui/Form/mkForm.h>
#include <Ui/Form/mkDropper.h>

namespace mk
{
	class MK_UI_EXPORT List : public Form, public Typed<List, Form>, public Styled<List>
	{
	public:
		List(Style* style = nullptr);

		using Typed<List, Form>::cls;
	};

	class MK_UI_EXPORT LabelList : public List
	{
	public:
		LabelList(StringVector labels = StringVector());
	};

	class MK_UI_EXPORT ButtonList : public List
	{
	public:
		ButtonList(StringVector labels = StringVector());
	};

	class MK_UI_EXPORT SortList : public List, public Typed<SortList, List>, public Dropper
	{
	public:
		SortList(Style* style);

		Form* swapdrop(Form* form, Dropper* source) { UNUSED(form); UNUSED(source); return nullptr; }
		bool candrop(Form* form, Dropper* source) { UNUSED(form); UNUSED(source); return false; }
		void dropin(Form* form, Dropper* source, size_t index) { UNUSED(form); UNUSED(source); UNUSED(index); }
		void dropout(Form* form, Dropper* source) { UNUSED(form); UNUSED(source); }

		virtual void moved(size_t from, size_t to) { UNUSED(from); UNUSED(to); }

		using Typed<SortList, List>::cls;
	};
}

#endif // MK_WIDGET_H_INCLUDED

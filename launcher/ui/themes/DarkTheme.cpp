// SPDX-License-Identifier: GPL-3.0-only
/*
 *  Prism Launcher - Minecraft Launcher
 *  Copyright (C) 2024 Tayou <git@tayou.org>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 3.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * This file incorporates work covered by the following copyright and
 * permission notice:
 *
 *      Copyright 2013-2021 MultiMC Contributors
 *
 *      Licensed under the Apache License, Version 2.0 (the "License");
 *      you may not use this file except in compliance with the License.
 *      You may obtain a copy of the License at
 *
 *          http://www.apache.org/licenses/LICENSE-2.0
 *
 *      Unless required by applicable law or agreed to in writing, software
 *      distributed under the License is distributed on an "AS IS" BASIS,
 *      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *      See the License for the specific language governing permissions and
 *      limitations under the License.
 *
 * ---
 *
 * This file has been modified from the upstream Prism Launcher "Dark" theme
 * into the sole, hard-coded application look. It is no longer meant to be
 * selectable alongside other themes -- see ThemeManager::applyCurrentlySelectedTheme()
 * and AppearanceWidget::loadThemeSettings(), both of which now force/lock this theme.
 */
#include "DarkTheme.h"

#include <QObject>

QString DarkTheme::id()
{
    return "dark";
}

QString DarkTheme::name()
{
    return QObject::tr("Prism");
}

QPalette DarkTheme::colorScheme()
{
    QPalette p;
    // Base surfaces -- near-black, slightly blue-tinted, like Modrinth App
    p.setColor(QPalette::Window, QColor(0x18, 0x18, 0x1b));
    p.setColor(QPalette::WindowText, QColor(0xed, 0xed, 0xf0));
    p.setColor(QPalette::Base, QColor(0x14, 0x14, 0x17));
    p.setColor(QPalette::AlternateBase, QColor(0x1e, 0x1e, 0x23));
    p.setColor(QPalette::ToolTipBase, QColor(0x26, 0x26, 0x2b));
    p.setColor(QPalette::ToolTipText, QColor(0xed, 0xed, 0xf0));
    p.setColor(QPalette::Text, QColor(0xed, 0xed, 0xf0));
    p.setColor(QPalette::Button, QColor(0x24, 0x24, 0x29));
    p.setColor(QPalette::ButtonText, QColor(0xed, 0xed, 0xf0));
    p.setColor(QPalette::BrightText, QColor(0xff, 0x55, 0x55));
    // Modrinth-green accent
    p.setColor(QPalette::Link, QColor(0x1b, 0xd9, 0x6a));
    p.setColor(QPalette::Highlight, QColor(0x1b, 0xd9, 0x6a));
    p.setColor(QPalette::HighlightedText, QColor(0x0a, 0x0a, 0x0a));
    p.setColor(QPalette::PlaceholderText, QColor(0x8c, 0x8c, 0x94));
    return fadeInactive(p, fadeAmount(), fadeColor());
}

double DarkTheme::fadeAmount()
{
    return 0.5;
}

QColor DarkTheme::fadeColor()
{
    return QColor(0x18, 0x18, 0x1b);
}

bool DarkTheme::hasStyleSheet()
{
    return true;
}

QString DarkTheme::appStyleSheet()
{
    return R"(
/* ===================== Modrinth-inspired reskin ===================== */
* { outline: none; }

QWidget {
    background-color: #18181b;
    color: #ededf0;
    selection-background-color: #1bd96a;
    selection-color: #0a0a0a;
    font-size: 13px;
}

QToolTip {
    background-color: #26262b;
    color: #ededf0;
    border: 1px solid #34343b;
    border-radius: 6px;
    padding: 4px 8px;
}

/* ---------- Main window / toolbars / menu bar ---------- */
QMainWindow, QDialog, QMessageBox {
    background-color: #18181b;
}

QMenuBar {
    background-color: #18181b;
    border-bottom: 1px solid #26262b;
    padding: 2px;
}
QMenuBar::item {
    background: transparent;
    padding: 4px 10px;
    border-radius: 6px;
}
QMenuBar::item:selected {
    background-color: #26262b;
}

QMenu {
    background-color: #1e1e23;
    border: 1px solid #2c2c33;
    border-radius: 8px;
    padding: 6px;
}
QMenu::item {
    padding: 6px 24px 6px 12px;
    border-radius: 6px;
    margin: 1px;
}
QMenu::item:selected {
    background-color: #1bd96a;
    color: #0a0a0a;
}
QMenu::separator {
    height: 1px;
    background: #2c2c33;
    margin: 6px 8px;
}

QToolBar {
    background-color: #18181b;
    border: none;
    spacing: 4px;
    padding: 6px;
}
QToolBar::separator {
    background-color: #2c2c33;
    width: 1px;
    margin: 4px 6px;
}
QToolButton {
    background: transparent;
    border: none;
    border-radius: 8px;
    padding: 6px 10px;
}
QToolButton:hover {
    background-color: #26262b;
}
QToolButton:pressed, QToolButton:checked {
    background-color: #2f2f36;
    color: #1bd96a;
}

QStatusBar {
    background-color: #18181b;
    border-top: 1px solid #26262b;
}

/* ---------- Buttons ---------- */
QPushButton {
    background-color: #24242a;
    color: #ededf0;
    border: 1px solid #34343b;
    border-radius: 8px;
    padding: 6px 16px;
    min-height: 18px;
}
QPushButton:hover {
    background-color: #2c2c33;
    border-color: #3d3d45;
}
QPushButton:pressed {
    background-color: #202025;
}
QPushButton:disabled {
    color: #6b6b72;
    background-color: #1e1e23;
    border-color: #26262b;
}
QPushButton:default {
    background-color: #1bd96a;
    color: #0a0a0a;
    border: 1px solid #1bd96a;
    font-weight: 600;
}
QPushButton:default:hover {
    background-color: #22e878;
}
QPushButton:default:pressed {
    background-color: #16b458;
}

/* ---------- Inputs ---------- */
QLineEdit, QPlainTextEdit, QTextEdit, QSpinBox, QDoubleSpinBox, QComboBox {
    background-color: #101013;
    border: 1px solid #2c2c33;
    border-radius: 8px;
    padding: 5px 8px;
    selection-background-color: #1bd96a;
    selection-color: #0a0a0a;
}
QLineEdit:focus, QPlainTextEdit:focus, QTextEdit:focus, QSpinBox:focus, QDoubleSpinBox:focus, QComboBox:focus {
    border: 1px solid #1bd96a;
}
QLineEdit:disabled, QComboBox:disabled {
    color: #6b6b72;
    background-color: #16161a;
}

QComboBox::drop-down {
    border: none;
    width: 24px;
}
QComboBox QAbstractItemView {
    background-color: #1e1e23;
    border: 1px solid #2c2c33;
    border-radius: 8px;
    selection-background-color: #1bd96a;
    selection-color: #0a0a0a;
    outline: none;
    padding: 4px;
}

QSpinBox::up-button, QSpinBox::down-button, QDoubleSpinBox::up-button, QDoubleSpinBox::down-button {
    background: transparent;
    border: none;
    width: 16px;
}

/* ---------- Checkboxes / radio ---------- */
QCheckBox, QRadioButton { spacing: 8px; }
QCheckBox::indicator, QRadioButton::indicator {
    width: 16px;
    height: 16px;
    border: 1px solid #3d3d45;
    background-color: #101013;
}
QCheckBox::indicator {
    border-radius: 5px;
}
QRadioButton::indicator {
    border-radius: 8px;
}
QCheckBox::indicator:checked, QRadioButton::indicator:checked {
    background-color: #1bd96a;
    border-color: #1bd96a;
}
QCheckBox::indicator:hover, QRadioButton::indicator:hover {
    border-color: #1bd96a;
}

/* ---------- Lists / trees / tables (instance grid, mod lists, etc.) ---------- */
QListView, QTreeView, QTableView {
    background-color: #18181b;
    border: 1px solid #26262b;
    border-radius: 10px;
    alternate-background-color: #1c1c21;
    padding: 4px;
}
QListView::item, QTreeView::item, QTableView::item {
    border-radius: 8px;
    padding: 6px;
    margin: 1px 2px;
}
QListView::item:hover, QTreeView::item:hover, QTableView::item:hover {
    background-color: #232329;
}
QListView::item:selected, QTreeView::item:selected, QTableView::item:selected {
    background-color: #1bd96a;
    color: #0a0a0a;
}
QHeaderView::section {
    background-color: #18181b;
    color: #9c9ca4;
    border: none;
    border-bottom: 1px solid #26262b;
    padding: 6px 8px;
    font-weight: 600;
}
QTableCornerButton::section {
    background-color: #18181b;
    border: none;
}

/* ---------- Tabs (redesigned as pill/segmented control) ---------- */
QTabWidget::pane {
    border: 1px solid #26262b;
    border-radius: 10px;
    top: -1px;
}
QTabBar {
    background: transparent;
}
QTabBar::tab {
    background: transparent;
    color: #9c9ca4;
    border: none;
    border-radius: 8px;
    padding: 7px 16px;
    margin: 4px 2px;
}
QTabBar::tab:hover {
    background-color: #232329;
    color: #ededf0;
}
QTabBar::tab:selected {
    background-color: #26262b;
    color: #1bd96a;
    font-weight: 600;
}

/* ---------- Group boxes / frames ---------- */
QGroupBox {
    border: 1px solid #26262b;
    border-radius: 10px;
    margin-top: 14px;
    padding-top: 10px;
    font-weight: 600;
}
QGroupBox::title {
    subcontrol-origin: margin;
    left: 12px;
    padding: 0 6px;
    color: #9c9ca4;
}

/* ---------- Scrollbars: thin, rounded, ghost track ---------- */
QScrollBar:vertical {
    background: transparent;
    width: 12px;
    margin: 2px;
}
QScrollBar::handle:vertical {
    background: #34343b;
    border-radius: 5px;
    min-height: 24px;
}
QScrollBar::handle:vertical:hover {
    background: #46464f;
}
QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
    height: 0;
    background: none;
}
QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {
    background: none;
}

QScrollBar:horizontal {
    background: transparent;
    height: 12px;
    margin: 2px;
}
QScrollBar::handle:horizontal {
    background: #34343b;
    border-radius: 5px;
    min-width: 24px;
}
QScrollBar::handle:horizontal:hover {
    background: #46464f;
}
QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {
    width: 0;
    background: none;
}

/* ---------- Progress bar ---------- */
QProgressBar {
    background-color: #101013;
    border: 1px solid #26262b;
    border-radius: 8px;
    text-align: center;
    color: #ededf0;
    min-height: 16px;
}
QProgressBar::chunk {
    background-color: #1bd96a;
    border-radius: 7px;
}

/* ---------- Sliders ---------- */
QSlider::groove:horizontal {
    background: #26262b;
    height: 4px;
    border-radius: 2px;
}
QSlider::handle:horizontal {
    background: #1bd96a;
    width: 14px;
    height: 14px;
    margin: -6px 0;
    border-radius: 7px;
}
QSlider::sub-page:horizontal {
    background: #1bd96a;
    border-radius: 2px;
}

/* ---------- Splitters ---------- */
QSplitter::handle {
    background-color: #26262b;
}
QSplitter::handle:hover {
    background-color: #1bd96a;
}

/* ---------- Sidebar-style dock/tool list (instance sidebar, category nav) ---------- */
QDockWidget {
    titlebar-close-icon: none;
    border: none;
}
QDockWidget::title {
    background: #18181b;
    padding: 8px;
    font-weight: 600;
    color: #9c9ca4;
}
)";
}

QString DarkTheme::tooltip()
{
    return "";
}
